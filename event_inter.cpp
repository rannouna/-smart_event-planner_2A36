#include "event_inter.h"
#include "ui_event_inter.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include"EVENEMENT.h"

#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include "ui_mainwindow.h"
#include"EVENEMENT.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include<QLineSeries>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QMediaPlayer>
#include <QFileDialog>
#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>




#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

event_inter::event_inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::event_inter)
{
    ui->setupUi(this);

    ui->lineEditID_Evenement->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Depense->setValidator(new QIntValidator(0,999999,this));
    ui->lineEditID_SUPP->setValidator(new QIntValidator(0,999999,this));
    ui->afficher->setModel(Etmp.afficher());

    //ARDUINOOO
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


}

event_inter::~event_inter()
{
    delete ui;
}


void event_inter::update_label()
{


}





void event_inter::on_modifier_clicked()
{
    int ID_EVENEMENT=ui->ID_EVENEMENTL_modif->text().toInt();
    QString TYPE=ui->lineEdit_TYPE->currentText();
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


void event_inter::on_ajouter_clicked()
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


void event_inter::on_supprimer_clicked()
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




void event_inter::on_rechercher_button_clicked()
{
    QString rech =ui->id_reparation->text();
        ui->afficher->setModel(Etmp.rechercher(rech));
}



void event_inter::on_radioButton_croissant_clicked()
{
     ui->afficher->setModel(Etmp.tri());
}

void event_inter::on_radioButton_dcroissant_clicked()
{
     ui->afficher->setModel(Etmp.trid());
}
// stat sur les type
void event_inter::on_statsmed_clicked()
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



    void event_inter::on_btn_imp_clicked()
    {
        QString strStream;
                                 QTextStream out(&strStream);

                                 const int rowCount = ui->afficher->model()->rowCount();
                                 const int columnCount = ui->afficher->model()->columnCount();
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
                                     if (!ui->afficher->isColumnHidden(column))
                                         out << QString("<th>%1</th>").arg(ui->afficher->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";

                                 // data table
                                 for (int row = 0; row < rowCount; row++) {
                                     out << "<tr>";
                                     for (int column = 0; column < columnCount; column++) {
                                         if (!ui->afficher->isColumnHidden(column)) {
                                             QString data =ui->afficher->model()->data(ui->afficher->model()->index(row, column)).toString().simplified();
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



void event_inter::on_afficher_doubleClicked(const QModelIndex &index)
{
    QString val = ui->afficher->model()->data(index).toString();
    val = val.mid(0,10);
    qDebug()<< val;

    QDate Date = QDate::fromString(val,"yyyy-MM-dd");
    ui->calendarWidget->setSelectedDate(Date);
}

void event_inter::on_calendarWidget_clicked(const QDate &date)
{
    QDate Date =  ui->calendarWidget->selectedDate();
    QString tmp = Date.toString("yyyy-MM-dd");
   QSqlQuery query;


   query =Etmp.request(tmp);
   bool test = false;
   if(query.exec())
   {
       while(query.next())
       {

           test = true;
           A.write_to_arduino("1");

           QMessageBox::information(nullptr, QObject::tr("Date exist"),
                       QObject::tr("Date exist.\n"
                                   "Click ok to exit."), QMessageBox::Cancel);
       }
   }
   if(test == false )
   {
       A.write_to_arduino("2");
       QMessageBox::warning(nullptr, QObject::tr("Date n'existe pas "),
                   QObject::tr("Date n'exist.\n"
                               "Click ok to exit."), QMessageBox::Cancel);

   }


}

void event_inter::on_btn_calculer_clicked()
{
    QString total=QString::number(Etmp.Calculer());

    ui->label_total->setText(total);

}
