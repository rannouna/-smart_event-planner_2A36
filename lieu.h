#ifndef LIEU_H
#define LIEU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<iostream>
#include<string>


using namespace std;
class lieu
{
    QString NOM_LIEU;
     QString  LOCALISATION;
      QString TYPE;
    int CODE_LIEU;
public:
    //constructeurs
     lieu();
     lieu (int,QString,QString,QString);
//getters
     int getcode_lieu() {return CODE_LIEU;}
     QString getnom_lieu() {return NOM_LIEU;}
     QString getlocalisation() {return LOCALISATION;}
     QString gettype() {return TYPE;}

//setters
     void setcode_lieu(int c) {this->CODE_LIEU=c;}
     void setnom_lieu(QString n) {NOM_LIEU=n;}
     void setlocalisation(QString l) {LOCALISATION= l;}
     void settype(QString t) {TYPE=t;}

//fonctionnalités de base relatives à l'entité lieu
    bool ajouter_lieu ();
    QSqlQueryModel * afficher_lieu();
    bool supprimer_lieu (int);
    bool modifier_lieu(int,QString,QString,QString);
};

#endif // LIEU_H
