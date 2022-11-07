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
     QString TYPE=ui->lineEdit_TYPE->text();
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

