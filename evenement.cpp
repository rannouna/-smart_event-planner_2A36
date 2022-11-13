#include "evenement.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QObject>

EVENEMENT::EVENEMENT()
{

}
EVENEMENT::EVENEMENT(int id, QDate date,int depense,QString type,QString theme)
{ this->ID_EVENEMENT=id;
    this->DATE_E=date;
    this->DEPENSE=depense;
    this->TYPE=type;
    this->THEME=theme;



}


QDate EVENEMENT::getDATE_E(){return DATE_E;}
int EVENEMENT::getID_EVENEMENT(){return ID_EVENEMENT;}
QString EVENEMENT::getTYPE(){return TYPE;}
QString EVENEMENT::getTHEME(){return THEME;}
int EVENEMENT::getDEPENSE(){return DEPENSE;}


void EVENEMENT::setDATE_E( QDate date){this->DATE_E=date;}
void EVENEMENT::setDEPENSE(int depense){this->DEPENSE=depense;}
void EVENEMENT::setTYPE(QString type){this->TYPE=type;}
void EVENEMENT::setTHEME(QString theme){this->THEME=theme;}
void EVENEMENT::setID_EVENEMENT(int id){this->ID_EVENEMENT=id;}

bool EVENEMENT::Ajouter()
{
    QSqlQuery query;//RELIEE AU BASE DE DONNEE (QSQLDATABASE)
    QString ID_EVENEMENT_string=QString::number(ID_EVENEMENT);
    QString DEPENSE_string=QString::number(DEPENSE);
          query.prepare("insert into EVENEMENT (ID_EVENEMENT,DATE_E,TYPE,THEME,DEPENSE) "
                        "values (:ID_EVENEMENT, :DATE_E, :TYPE, :THEME, :DEPENSE)");
          query.bindValue(":ID_EVENEMENT",ID_EVENEMENT_string);
          query.bindValue(":DATE_E",DATE_E);
          query.bindValue(":TYPE",TYPE);
          query.bindValue(":THEME",THEME);
          query.bindValue(":DEPENSE",DEPENSE_string);
          return query.exec();
}

QSqlQueryModel* EVENEMENT::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(" SELECT* from EVENMENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE-E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DEPENSE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("THEME"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_EVENEMENT"));
    return model;
}

bool EVENEMENT::supprimer(int ID_EVENEMENT)
{
    QSqlQuery query;
    QString ID_EVENEMENT_string=QString::number(ID_EVENEMENT);
    query.prepare("Delete from EVENEMENT where ID_EVENEMENT= :ID_EVENEMENT");
    query.bindValue(":ID_EVENEMENT",ID_EVENEMENT_string);
    return query.exec();

}
//sqlquery data base s
bool EVENEMENT::modifier()
{
    QSqlQuery query;
    QString ID_EVENEMENT_string=QString::number(ID_EVENEMENT);
    query.prepare("update EVENEMENT set DATE_I=:DATE_I, where ID_EVENEMENT=:ID_EVENEMENT");
    query.bindValue(":ID_EVENEMENT",ID_EVENEMENT_string);
    query.bindValue(":DATE_E",DATE_E);

   return query.exec();

}
QSqlQueryModel *EVENEMENT::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from EVENEMENT where ID_EVENEMENT LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *EVENEMENT::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM EVENEMENT ORDER BY TYPE ");
   q->exec();
   model->setQuery(*q);

   return model;
}

QSqlQueryModel *EVENEMENT::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM EVENEMENT ORDER BY TYPE DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}
