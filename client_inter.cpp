#include "client_inter.h"
#include "ui_client_inter.h"

client_inter::client_inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client_inter)
{
    ui->setupUi(this);
    //affichage contenu base
    show_tables();

    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}

client_inter::~client_inter()
{
    delete ui;
}
//recuperation des donnees du formulaire

QString client_inter::cin() const { //line edit

    return ui->cin->text();
}

QString client_inter::nom() const { //line edit

    return ui->nom->text();
}

int client_inter::age() const{ //integer

    return ui->age->value();
}

QString client_inter::adresse() const { //line edit

    return ui->adresse->text();
}

QString client_inter::mail() const { //line edit

    return ui->mail->text();
}

QString client_inter::code() const { //line edit

    return ui->code_event->text();
}

//remplissage des champs du formulaire a partir de la base

void client_inter::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from CLIENT where CIN= :cin");
    query.bindValue(":cin", selected);
    query.exec();
    while(query.next()){
        ui->cin->setText(query.value(0).toString()); //line edit
  ui->nom->setText(query.value(1).toString()); //line edit
    ui->age->setValue(2);// integer
    ui->adresse->setText(query.value(3).toString()); //line edit
    ui->mail->setText(query.value(4).toString()); //line edit
    ui->code_event->setText(query.value(5).toString()); //line edit
        }

}


/************************************ CRUD + Tri **************************************/

void client_inter::on_Add_clicked()
{
    //recuperation des donnees
      int i=age();
      QString s1=cin();
      QString s2=nom();
      QString s3=adresse();
      QString s4=mail();
      QString s5=code();

      //ajout
      client mc(i,s1,s2,s3,s4,s5);
      mc.ajouter();

  //refresh du tableau (affichage)
   show_tables();
}

void client_inter::on_tableau_clicked(const QModelIndex &index)
{
    selected=ui->tableau->model()->data(index).toString();
}

void client_inter::on_tableau_doubleClicked(const QModelIndex &index)
{
    fill_form(selected);
}

void client_inter::on_Update_clicked()
{
    //recuperation des donnees
    int i=age();
    QString s1=selected;
    QString s2=nom();
    QString s3=adresse();
    QString s4=mail();
    QString s5=code();

      //mofication
      client mc(i,selected,s2,s3,s4,s5);
      mc.modifier(selected);



    //refresh du tableau (affichage)
     show_tables();

}

void client_inter::on_Delete_clicked()
{
    client mc;
  mc.supprimer(selected);

 //refresh du tableau (affichage)
   show_tables();
}

//affichage + metier tri
void client_inter::show_tables(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(sel_col); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableau->setModel(proxy);

}

/************************************ Metiers **************************************/

void client_inter::on_comboBox_currentIndexChanged(int index)
{
    sel_col=ui->comboBox->currentIndex()-1;
    proxy->setFilterKeyColumn(sel_col); // chercher dans tout le tableau (-1) ou donner le numero de la colonne
}

void client_inter::on_recherche_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void client_inter::on_stat_clicked()
{
    s = new stat_age();

  s->setWindowTitle("statistique Clients - Age");
  s->choix_pie();
  s->show();
}

void client_inter::on_Export_pdf_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableau->model()->rowCount();
                const int columnCount =ui->tableau->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des COLIS</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableau->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableau->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableau->isColumnHidden(column)) {
                                   QString data = ui->tableau->model()->data(ui->tableau->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("Clients.pdf");
        document->print(&printer);
}

//mailing
void  client_inter::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   client_inter::sendMail()
{
    Smtp* smtp = new Smtp("sassi.yasmine@esprit.tn",mail_pass, "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("sassi.yasmine@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("sassi.yasmine@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   client_inter::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}


