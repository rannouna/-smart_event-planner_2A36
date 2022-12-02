#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "employer.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
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
#include <QIntValidator>
#include "signe.h"
#include "ui_signe.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_employer->setModel(etmp.afficher());
    ui->le_id->setValidator(new QIntValidator(0,999999,this));
        ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
        ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
        ui->le_poste->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       //  ui->date_de_naissance->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));


}

MainWindow::~MainWindow()
{
    delete ui;
}



        Employer e;


void MainWindow::on_pb_ajouter_clicked()
{


    Employer e;





    //get lines


e.setnom(ui->le_nom->text());
e.setprenom(ui->le_prenom->text());
e.setposte(ui->le_poste->text());
e.setdate_de_naissance(ui->date_de_naissance->text());
e.setid_employer(ui->le_id->text());






bool test=e.ajouter();
//refresh tab viwer


if(test)
{
    ui->tab_employer->setModel(etmp.afficher());
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr(" done.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr(" failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}
}


void MainWindow::on_bt_supp_clicked()
{
    int id_employer=ui->le_id_supp->text().toInt();
    bool test=etmp.supprimer(id_employer);
    if (test)
    {
        ui->tab_employer->setModel(etmp.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectué\n"
                                    "click cancel to exit."), QMessageBox::Cancel);

          }
            else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Suppression non effectué\n""click cancel to exit"), QMessageBox::Cancel);



        }




void MainWindow::on_pb_modifier_clicked()
{
    Employer res;
     int num= ui->modif->text().toInt();
     res.setnom(ui->le_nom->text());
     res.setprenom(ui->le_prenom->text());
     res.setposte(ui->le_poste->text());
     res.setdate_de_naissance(ui->date_de_naissance->text());
     res.setid_employer(ui->le_id->text());

     bool test=res.modifier(num);
     if(test)
     {
         ui->tab_employer->setModel(etmp.afficher());
     }



}



void MainWindow::on_radioButton_clicked()

{

    ui->tab_employer->setModel(etmp.trieid_employer());

}






void MainWindow::on_radioButton_2_clicked()

{

    ui->tab_employer->setModel(etmp.trienom());

}




void MainWindow::on_radioButton_3_clicked()
{

    ui->tab_employer->setModel(etmp.trieprenom());

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
QString rech = ui->lineEdit->text();



                etmp.recherche(ui->tab_employer,rech);



                if (ui->lineEdit->text().isEmpty())



                {



                    ui->tab_employer->setModel(etmp.afficher());



                }
}










void MainWindow::on_pb_ajouter_2_clicked()
{
    etmp.telechargerPDF();


               QMessageBox::information(nullptr,QObject::tr("OK"),



                          QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from EMPLOYE where POSTE = 'garde du corps'");
                   float dispo1=model->rowCount();

                   model->setQuery("select * from EMPLOYE where POSTE = 'technicien'");
                   float dispo=model->rowCount();

                   model->setQuery("select * from EMPLOYE where POSTE = 'serveur'");
                   float dispo3=model->rowCount();

                   float total=dispo1+dispo+dispo3;
                       QString a=QString("garde du corps " +QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("technicien " +QString::number((dispo*100)/total,'f',2)+"%" );
                       QString c=QString("serveur " +QString::number((dispo3*100)/total,'f',2)+"%" );
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
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    qDebug() << data;
    if(c.length()+data.length()>12)
    {int j=0;
        for(int i=c.length();i<12;i++)
        {
            if(data[j]!='/' || data[j]!='r' || data[j]!='n' )
            c[i]=data[j];
            j++;
        }
        t++;
    }
    else
    {
        c+=data;
    }
    qDebug()<<c;

    if(c == " 43 B7 8F 92" && c.length()==12)

    {

        QMessageBox::information(this,"Login","Acess granted");
        //hide();
        MainWindow m;
        //new MainWindow(this);
         m.show();
         A.write_to_arduino("1");

    }
    if (c != " 43 B7 8F 92"  && c.length()==12)
    {
        A.write_to_arduino("2");
    }

    if(c.length()>=12)
    {
        t=0;
        c="";
    }


}
