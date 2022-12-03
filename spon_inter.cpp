#include "spon_inter.h"
#include "ui_spon_inter.h"
#include "qmessagebox.h"
#include "connection.h"
#include "sponsor.h"
#include "arduino.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include  <QDesktopServices>
spon_inter::spon_inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::spon_inter)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    ui->tableView_2->setModel(etmp.afficherclassification());
    //controle de saisie
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_type->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
     ui->le_prix->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numero->setValidator(new QIntValidator(1111111,9999999,this));

   int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
             //A.write_to_arduino("0");
            // A.read_from_arduino();
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).
             //A.write_to_arduino("0");
            // A.read_from_arduino();

}

spon_inter::~spon_inter()
{
    delete ui;
}


void spon_inter::on_pb_ajouter_clicked()
{
    sponsors res;

   /*int id=ui->le_id->text().toInt();
   QString prix=ui->le_prix->text();
   QString type=ui->le_type->text();
   int numero=ui->le_numero->text().toInt();
   sponsors C(id,prix,type,numero);
   */
    res.setid(ui->le_id->text());
    res.setprix(ui->le_prix->text());
    res.settype(ui->le_type->text());
    res.setnumero(ui->le_numero->text());
    bool test=res.ajouter();
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
          A.write_to_arduino("1");

    }
else{
          A.write_to_arduino("0");
    }
}
void spon_inter::on_pb_supprimer_clicked()
{
    int id=ui->le_id->text().toInt();
    bool test=etmp.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
        A.write_to_arduino("3");

    }
    else{
              A.write_to_arduino("0");
        }
}
void spon_inter::on_pb_modifier_clicked()
{
    sponsors res;
    int num0=ui->num_modif->text().toInt() ;
    res.setid(ui->le_id->text());
    res.setprix(ui->le_prix->text());
    res.settype(ui->le_type->text());
    res.setnumero(ui->le_numero->text());
    bool test=res.modifier(num0);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
        A.write_to_arduino("2");

    }
    else{
              A.write_to_arduino("0");
        }
}
void spon_inter::on_radioButton_clicked()

{
    ui->tableView->setModel(etmp.trieid());
}

void spon_inter::on_radioButton_2_clicked()

{
    ui->tableView->setModel(etmp.trienumero());
}
void spon_inter::on_radioButton_3_clicked()

{
    ui->tableView->setModel(etmp.trietype());
}


void spon_inter::on_le_id_2_textChanged(const QString &arg1)
{
    QString rech = ui->le_id_2->text();

                     etmp.recherche(ui->tableView,rech);

                     if (ui->le_id_2->text().isEmpty())

                     {

                         ui->tableView->setModel(etmp.afficher());

                     }
}


void spon_inter::on_pb_ajouter_2_clicked()
{
    etmp.telechargerPDF();



            QMessageBox::information(nullptr,QObject::tr("OK"),

                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}


void spon_inter::on_pb_ajouter_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("select * from SPONSOR where TYPE_C = 'societe'");
               float dispo1=model->rowCount();

               model->setQuery("select * from SPONSOR where TYPE_C = 'restaurant'");
               float dispo=model->rowCount();

               model->setQuery("select * from SPONSOR where TYPE_C = 'boutique'");
               float dispo3=model->rowCount();

               float total=dispo1+dispo+dispo3;
                   QString a=QString("societe " +QString::number((dispo1*100)/total,'f',2)+"%" );
                   QString b=QString("restaurant  " +QString::number((dispo*100)/total,'f',2)+"%" );
                   QString c=QString("boutique  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                   QPieSeries *series = new QPieSeries();
                   series->append(a,dispo1);
                   series->append(b,dispo);
                   series->append(c,dispo3);
               if (dispo1!=0)
               {QPieSlice *slice = series->slices().at(0);
                   slice->setLabelVisible();
                   slice->setPen(QPen());}
               if ( dispo!=0)
               {
                   QPieSlice *slice1 = series->slices().at(1);
                   slice1->setLabelVisible();
                   slice1->setPen(QPen());
               }
               if (dispo3!=0)
               {QPieSlice *slice = series->slices().at(2);
                   slice->setLabelVisible();
                   slice->setPen(QPen());}

               QChart *chart = new QChart();


               chart->addSeries(series);
               chart->setTitle("Nombre: "+ QString::number(total));



               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1300,800);
               chartView->show();
}

void spon_inter::on_pb_ajouter_4_clicked()
{
   ui->tableView_2->setModel(etmp.classification());

}

void spon_inter::on_pb_ajouter_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21641220555", QUrl::TolerantMode));
}
void spon_inter::update_label()
{

}

void spon_inter::update_label2()
{

}
