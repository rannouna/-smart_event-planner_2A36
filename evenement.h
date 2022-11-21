#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>

class EVENEMENT
{
    QString  TYPE,THEME;
    int ID_EVENEMENT,DEPENSE;
    QDate DATE_E;
public:
    EVENEMENT( int,QDate,int,QString,QString);
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
   QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();
    QSqlQueryModel * trid();

    QSqlQuery request(QString);
    int Calculer();




};

#endif // EVENEMENT_H
