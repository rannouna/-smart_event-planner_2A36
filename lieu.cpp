#include "lieu.h"
#include<iostream>
#include<string>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtDebug>
#include<QObject>

using namespace std;


lieu :: lieu()
{  CODE_LIEU=0;
    NOM_LIEU=" ";
    LOCALISATION=" ";
    TYPE=" ";
}

lieu::lieu(int CODE_LIEU,QString TYPE,QString NOM_LIEU,QString LOCALISATION)
{
    this->CODE_LIEU=CODE_LIEU;
    this->NOM_LIEU=NOM_LIEU;
    this->LOCALISATION=LOCALISATION;
    this->TYPE=TYPE;

}
bool lieu :: ajouter_lieu()
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(CODE_LIEU);
          query.prepare("INSERT INTO LIEU (CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE) "
                        "VALUES (:CODE_LIEU, :NOM_LIEU, :LOCALISATION,:TYPE)");
          query.bindValue(":CODE_LIEU",code_lieu_string );
          query.bindValue(":NOM_LIEU", NOM_LIEU);
          query.bindValue(":LOCALISATION", LOCALISATION);
          query.bindValue(":TYPE", TYPE);

         return  query.exec();

}


QSqlQueryModel* lieu::afficher_lieu()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM LIEU");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_LIEU"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_LIEU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOCALISATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}

bool lieu:: supprimer_lieu (int CODE_LIEU)
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(CODE_LIEU);

    query.prepare(" Delete from LIEU where code_lieu=:CODE_LIEU");
    query.bindValue(":CODE_LIEU", code_lieu_string);
  return  query.exec();
}


bool lieu ::modifier_lieu(int CODE_LIEUM, QString NOM_LIEUM,QString LOCALISATIONM,QString TYPEM)
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(CODE_LIEUM);
          query.prepare("UPDATE LIEU SET CODE_LIEU=:CODE_LIEU,NOM_LIEU=:NOM_LIEU,LOCALISATION=:LOCALISATION,TYPE=:TYPE WHERE CODE_LIEU=:CODE_LIEU ");

          query.bindValue(":CODE_LIEU",code_lieu_string );
          query.bindValue(":NOM_LIEU", NOM_LIEUM);
          query.bindValue(":LOCALISATION", LOCALISATIONM);
          query.bindValue(":TYPE", TYPEM);

         return  query.exec();

}


