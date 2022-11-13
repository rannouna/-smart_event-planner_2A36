#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"evenement.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent):
 QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditID_Evenement->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Depense->setValidator(new QIntValidator(0,999999,this));
    ui->lineEditID_SUPP->setValidator(new QIntValidator(0,999999,this));
    ui->afficher->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_modifier_clicked()
{
    int ID_EVENEMENT=ui->ID_EVENEMENTL_modif->text().toInt();
    QString TYPE=ui->lineEdit_TYPE->text();
    QString THEME=ui->lineEdit_THME->text();
    int DEPENSE=ui->lineEdit_Depense->text().toInt();
    QDate DATE_E=ui->dateEdit->date();
   EVENEMENT E(ID_EVENEMENT , DATE_E, DEPENSE,TYPE,THEME);
    bool test=E.modifier();
    if(test)
    {
        ui->afficher->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);


}


void MainWindow::on_ajouter_clicked()
{
       int ID_EVENEMENT=ui->lineEditID_Evenement->text().toInt();
       QDate DATE_E=ui->Date_E_Edit->date();
     int DEPENSE=ui->lineEdit_Depense->text().toInt();
     QString TYPE=ui->lineEdit_TYPE->currentText();
     QString THEME=ui->lineEdit_THME->text();




   EVENEMENT E(ID_EVENEMENT,DATE_E,DEPENSE,TYPE,THEME);
    bool test=E.Ajouter();
    if(test)
   {
        ui->afficher->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout d'un evenement"),
                                 QObject::tr("Ajout effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
   }
    else
        QMessageBox::critical(nullptr,QObject::tr("Ajout d'un evenement"),
                              QObject::tr("Ajout non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
}


void MainWindow::on_supprimer_clicked()
{
    int ID_EVENEMENT=ui->lineEditID_SUPP->text().toInt();
     bool test=Etmp.supprimer(ID_EVENEMENT);
     if(test)
     {
         ui->afficher->setModel(Etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("Suppression d'un evenement"),
                                  QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Suppression d'un evenement"),
                               QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

 }




void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->id_reparation->text();
        ui->afficher->setModel(Etmp.rechercher(rech));
}



void MainWindow::on_radioButton_croissant_clicked()
{
     ui->afficher->setModel(Etmp.tri());
}

void MainWindow::on_radioButton_dcroissant_clicked()
{
     ui->afficher->setModel(Etmp.trid());
}
// stat sur les type
void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from EVENEMENT where TYPE='Birthday' ");
     int number1=model->rowCount();
     model->setQuery("select * from EVENEMENT where TYPE='Mariage' ");
     int number2=model->rowCount();
     model->setQuery("select * from EVENEMENT where TYPE='Engament' ");
     int number3=model->rowCount(); // calculer le nombre des evenement pour engament
    model->setQuery("select * from EVENEMENT where TYPE='Babyshower' ");
          int number4=model->rowCount();
          model->setQuery("select * from EVENEMENT where TYPE='Brideparty' ");
          int number5=model->rowCount();
     model->setQuery("select * from EVENEMENT where TYPE='Autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("Birthday"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Mariage"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Engament"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Babyshower" +QString::number((number4*100)/total,'f',2)+"%" );

      QString e = QString("Brideparty" +QString::number((number5*100)/total,'f',2)+"%" );

     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );


     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par type des evenements"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}

void MainWindow::on_btn_imp_clicked()
{
    QString strStream;
                             QTextStream out(&strStream);

                             const int rowCount = ui->tablevol->model()->rowCount();
                             const int columnCount = ui->tablevol->model()->columnCount();
                             QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                             out <<"<html>\n"
                                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 << "<title>ERP - COMmANDE LIST<title>\n "
                                 << "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                 "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  EVENEMENT ******"+TT+" </strong></h1>"
                                 "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                   "</br> </br>";
                             // headers
                             out << "<thead><tr bgcolor=#d6e5ff>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tablevol->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tablevol->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tablevol->isColumnHidden(column)) {
                                         QString data =ui->tablevol->model()->data(ui->tablevol->model()->index(row, column)).toString().simplified();
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

                             QPrinter printer;

                             QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                             if (dialog->exec() == QDialog::Accepted) {
                                 document->print(&printer);
                             }

                             delete document;


}

    void MainWindow::on_pb_exit_clicked()
    {
        QMessageBox::StandardButton reply = QMessageBox :: question (this,
                               "EXIT","Voulez-vous vraiment sortir ?",
                            QMessageBox :: Yes | QMessageBox :: No);
        if (reply == QMessageBox :: Yes)
            {QApplication ::quit();}
        else {
            qDebug() <<"No is clicked";
             }

    }


    void MainWindow::on_btn_imp_clicked()
    {
        QString strStream;
                                 QTextStream out(&strStream);

                                 const int rowCount = ui->tab_em->model()->rowCount();
                                 const int columnCount = ui->tab_em->model()->columnCount();
                                 QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                                 out <<"<html>\n"
                                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                     << "<title>ERP - COMmANDE LIST<title>\n "
                                     << "</head>\n"
                                     "<body bgcolor=#ffffff link=#5000A0>\n"
                                     "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                                     "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                       "</br> </br>";
                                 // headers
                                 out << "<thead><tr bgcolor=#d6e5ff>";
                                 for (int column = 0; column < columnCount; column++)
                                     if (!ui->tab_em->isColumnHidden(column))
                                         out << QString("<th>%1</th>").arg(ui->tab_em->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";

                                 // data table
                                 for (int row = 0; row < rowCount; row++) {
                                     out << "<tr>";
                                     for (int column = 0; column < columnCount; column++) {
                                         if (!ui->tab_em->isColumnHidden(column)) {
                                             QString data =ui->tab_em->model()->data(ui->tab_em->model()->index(row, column)).toString().simplified();
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

                                 QPrinter printer;

                                 QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                 if (dialog->exec() == QDialog::Accepted) {
                                     document->print(&printer);
                                 }

                                 delete document;


    }
