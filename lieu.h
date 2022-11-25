#ifndef LIEU_H
#define LIEU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<iostream>
#include<string>

#include <QtCharts>
#include <QColor>
using namespace std;
class lieu
{
    QString NOM_LIEU;
     QString  LOCALISATION;
      QString TYPE;
    int CODE_LIEU;
      QString DISPONIBILITE;
public:
    //constructeurs
     lieu();
     lieu (int,QString,QString,QString, QString);
//getters
     int getcode_lieu() {return CODE_LIEU;}
     QString getnom_lieu() {return NOM_LIEU;}
     QString getlocalisation() {return LOCALISATION;}
     QString gettype() {return TYPE;}
     QString getdisponibilite() {return DISPONIBILITE;}
//setters
     void setcode_lieu(int c) {this->CODE_LIEU=c;}
     void setnom_lieu(QString n) {NOM_LIEU=n;}
     void setlocalisation(QString l) {LOCALISATION= l;}
     void settype(QString t) {TYPE=t;}
     void setdisponiblite(QString dispo) {DISPONIBILITE=dispo;}
//fonctionnalités de base relatives à l'entité lieu
    bool ajouter_lieu ();
    QSqlQueryModel * afficher_lieu();
    bool supprimer_lieu (int);
    bool modifier_lieu(int,QString,QString,QString,QString);
    bool recherche_lieu(int);
    QSqlQueryModel * afficher_code_lieu_rechercher(QString);
    QSqlQueryModel * afficher_nom_lieu_rechercher(QString);
    QSqlQueryModel * afficher_localisation_lieu_rechercher(QString);
   QSqlQueryModel* tri_code();
   QSqlQueryModel* tri_dispo();

   bool recherche_lieu_dispo(QString code_lieu);

   QString pdf(int code);

   int reserva(int ,QString);

};

#endif // LIEU_H
