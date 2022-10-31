# -smart_event-planner_2A36
#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>

class EVENEMENT
{
    QString  TYPE,THEME;
    int ID_EVENEMENT,DEPENSE;
    QDate DATE_E;
public:
    EVENEMENT( QDate,int,QString,QString,int);
 EVENEMENT();


     QDate getDATE_E();
    int getID_EVENEMENT();
    QString getTYPE();
    QString getTHEME();
  int getDEPENSE();


    void setDATE_E(  QDate);
    void setDEPENSE(int);
    void setTYPE(QString);
    void setTHEME(QString);
    void setID_EVENEMENT(int);

    bool Ajouter();
    bool supprimer(int);
    bool modifier();
   QSqlQueryModel *afficher();





};

#endif // EVENEMENT_H
