#include "lieu_inter.h"
#include "ui_lieu_inter.h"
#include "lieu.h"
#include "arduino.h"
#include <QMessageBox>
#include <QIntValidator>


using namespace std;

//afficher_lieu
lieu_inter::lieu_inter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lieu_inter)
{
    ui->setupUi(this);

    ui->code_lieu_3->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_lieu->setModel(LI.afficher_lieu());
    QPixmap pix("Users/felah/Downloads/picture.jpg");
    ui->label_pic_2->setPixmap(pix);
    int rete=A.connect_arduino(); // lancer la connexion à arduino
            switch(rete){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(login_arduino_lieu())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
             //map
              QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                                 QCoreApplication::organizationName(), QCoreApplication::applicationName());

              ui->WebBrowser_lieu->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
}

lieu_inter::~lieu_inter()
{
    delete ui;
}

//ajouter lieu
void lieu_inter::on_pb_ajouter_lieu_clicked()
{
    int CODE_LIEU=ui->code_lieu_3->text().toInt();
    QString NOM_LIEU=ui->Nom_lieu_2->text();
    QString LOCALISATION=ui->Localisation_lieu->currentText();
    QString TYPE=ui->Type_lieu->currentText();
     QString DISPONIBILITE="oui";

    lieu LI(CODE_LIEU,TYPE,NOM_LIEU,LOCALISATION,DISPONIBILITE);
    bool test =LI.ajouter_lieu();
    if (test)
    {
        //actualiser pour l'affichage

        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
        ui->tab_lieu->setModel(LI.afficher_lieu());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);

}
//supprimer
void lieu_inter::on_pb_supprimer_lieu_clicked()
{
    lieu LI;
        bool test=false ,test_recherche;
    int code_lieu=ui->code_lieu_4->text().toInt();
    test_recherche=LI.recherche_lieu(code_lieu);
       //LI.SetCodelieu(ui->supprimer_code_lieu->text().toInt());
       // bool test =LI.supprimer_lieu(LI.getCodelieu());

    if (test_recherche==false)
               {
                    test =LI.supprimer_lieu(code_lieu); //Appel de la méthode supprimer via l’attribut LI
               }

        if (test==true)
        {
            QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("suppression effectué\n"
                                                                         "Click Cancel to exit"), QMessageBox::Cancel);
        }
        else
         { QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("suppression non effectué\n"
                                                                               "Click Cancel to exit"), QMessageBox::Cancel);}
        ui->tab_lieu->setModel(LI.afficher_lieu());
         }


//modifier
void lieu_inter::on_pb_modifier_lieu_clicked()
{
    int CODE_LIEU=ui->code_lieu_4->text().toInt();
    QString NOM_LIEU=ui->Nom_lieu_2->text();
    QString LOCALISATION=ui->Localisation_lieu->currentText();
    QString TYPE=ui->Type_lieu->currentText();
    QString DISPONIBILITE=ui->dispo_lieu->currentText();


    bool test =LI.modifier_lieu(CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE,DISPONIBILITE);

    if (test)
    {
        //actualiser pour l'affichage

        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("modifier effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    ui->tab_lieu->setModel(LI.afficher_lieu());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("modifier non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);
}
//trier
void lieu_inter::on_trier_lieu_currentIndexChanged(int index)
{
if(index==0)
    ui->tab_lieu->setModel(LI.afficher_lieu());
if(index==1)
    ui->tab_lieu->setModel(LI.tri_code());
if(index==2)
    ui->tab_lieu->setModel(LI.tri_dispo());
}


//rechercher selon :
void lieu_inter::on_nom_lieu_a_recherche_textChanged(const QString &arg1)
{
    ui->tab_lieu->setModel(LI.afficher_nom_lieu_rechercher(arg1));
}

void lieu_inter::on_code_lieu_a_recherche_textChanged(const QString &arg1)
{
    ui->tab_lieu->setModel(LI.afficher_code_lieu_rechercher(arg1));
}

void lieu_inter::on_loc_lieu_a_recherche_textChanged(const QString &arg1)
{
    ui->tab_lieu->setModel(LI.afficher_localisation_lieu_rechercher(arg1));
}



//PDF
void lieu_inter::on_pb_pdf_lieu_clicked()
{
    int code=ui->code_lieu_3->text().toInt();
    QString pdf=LI.pdf(code);
    ui->pdf_lieu->setText(pdf);
    QPrinter printer;
    printer.setPrinterName("Lieu");
    printer.setPageSize(QPrinter::A4);
    QPrintDialog dialog(&printer,this) ;
    if (dialog.exec()== QDialog::Rejected) return;
    ui->pdf_lieu->print(&printer);}




//afficher ajouter inverser
void lieu_inter::on_tab_lieu_clicked(const QModelIndex &index)
{
    QString val=ui->tab_lieu->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM LIEU WHERE code_lieu= :code_lieu");
    qry.bindValue(":code_lieu",val);
    if(qry.exec())
    {
        while(qry.next())
        {

            ui->code_lieu_3->setText(qry.value(0).toString());
            ui->code_lieu_4->setText(qry.value(0).toString());
            ui->Nom_lieu_2->setText(qry.value(1).toString());
            ui->Localisation_lieu->setCurrentText(qry.value(2).toString());
            ui->Type_lieu->setCurrentText(qry.value(3).toString());
            ui->dispo_lieu->setCurrentText(qry.value(4).toString());

        }
    }
}




void lieu_inter::on_upload_lieu_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images(*png *.xpm *.jpg"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog :: getOpenFileName(this,tr("open Images"),"Users/felah/Downloads/picture",tr("Image_Files(*.png *.jpg *.bmp)"));

if (! fileName.isEmpty())
   {
        QImage image(fileName);
      ui->label_pic_2->setPixmap(QPixmap::fromImage(image));
    }
}



void lieu_inter::on_reserver_lieu_clicked()
{
    int id_evenement=ui->Id_evenement->text().toInt();
    QString Type=ui->Type_lieu_2->currentText();
    int code_lieu=0;
    code_lieu=LI.reserva(id_evenement,Type);
    QString code_string=QString::number(code_lieu);
    if(code_lieu!=0)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("Lieu reservé\n"
                                           "Click Cancel to Exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                       QObject::tr("Lieu non reservé\n"
                                           "Click Cancel to Exit."),QMessageBox::Cancel);
    }
    ui->tab_lieu->setModel(LI.afficher_lieu());
}



void lieu_inter::on_stat_lieu_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from LIEU where TYPE='Restaurant' ");
     int number1=model->rowCount();
     model->setQuery("select * from LIEU where TYPE='Hotel' ");
     int number2=model->rowCount();


     int total=number1+number2 ;

     QString a = QString("Restaurant"+ QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Hotel"+ QString::number((number2*100)/total,'f',2)+"%" );


  QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);

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

             // Create the chart widget
             QChart *chart = new QChart();

             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par type des evenements" + QString::number(total));
             chart->legend()->hide();

             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}

void lieu_inter::login_arduino_lieu(){

    data_lieu=A.read_from_arduino();

   QString ch1=QString::fromUtf8(data_lieu);

if(ch1=="*")
{
    ch="";
}else
{
         ch=ch+ch1;
}
         ui->ard_lieu->setText(ch);
}

void lieu_inter::on_recherch_ard_lieu_clicked()
{
    QSqlQuery qry;
    QString lieu,dispo;
   QString code_ard=ui->ard_lieu->text();
    qry.prepare("select * from LIEU where CODE_LIEU= :code" );
    qry.bindValue(":code", code_ard );
    if (qry.exec())
    {
        while(qry.next())
        {
            dispo=qry.value(4).toString();
        }
    }

        if(dispo=="oui")
        {
            A.write_to_arduino("1")  ;

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                           QObject::tr("disponible\n"
                                               "Click Cancel to Exit."),QMessageBox::Cancel);




        }
        else
        {
              A.write_to_arduino("2")  ;
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                           QObject::tr("non disponible\n"
                                               "Click Cancel to Exit."),QMessageBox::Cancel);



}
}
