#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lieu.h"
#include <QMessageBox>
#include <QIntValidator>
using namespace std;

//afficher_lieu
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Code_lieu->setValidator(new QIntValidator(100,9999999,this));
    ui->tab_lieu->setModel(LI.afficher_lieu());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int CODE_LIEU=ui->Code_lieu->text().toInt();
    QString NOM_LIEU=ui->Nom_lieu->text();
    QString LOCALISATION=ui->Localisation->text();
    QString TYPE=ui->Type->text();

    lieu LI(CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE);

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

void MainWindow::on_pb_supprimer_clicked()
{
    lieu LI;
    int code_lieu=ui->supprimer_code_lieu->text().toInt();

   //LI.SetCodelieu(ui->supprimer_code_lieu->text().toInt());
   // bool test =LI.supprimmer_lieu(LI.getCodelieu());
    bool test =LI.supprimer_lieu(code_lieu);

    if (test)
    {
        //actualiser pour l'affichage

        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("suppression effectué\n"
                                                                                             "Click Cancel to exit"), QMessageBox::Cancel);

ui->tab_lieu->setModel(LI.afficher_lieu());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("suppression non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    int CODE_LIEU=ui->Code_lieu_2->text().toInt();
    QString NOM_LIEU=ui->Nom_lieu_2->text();
    QString LOCALISATION=ui->Localisation_2->text();
    QString TYPE=ui->Type_2->text();


    bool test =LI.modifier_lieu(CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE);

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
