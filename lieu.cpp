#include "lieu.h"
#include<iostream>
#include<string>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtDebug>
#include<QObject>
#include <QtCharts>
#include <QColor>
using namespace std;


lieu :: lieu()
{  CODE_LIEU=0;
    NOM_LIEU=" ";
    LOCALISATION=" ";
    TYPE=" ";
    DISPONIBILITE="oui";
}

lieu::lieu(int CODE_LIEU,QString TYPE,QString NOM_LIEU,QString LOCALISATION,QString DISPONIBILITE)
{
    this->CODE_LIEU=CODE_LIEU;
    this->NOM_LIEU=NOM_LIEU;
    this->LOCALISATION=LOCALISATION;
    this->TYPE=TYPE;
    this->DISPONIBILITE=DISPONIBILITE;
}
bool lieu :: ajouter_lieu()
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(CODE_LIEU);
          query.prepare("INSERT INTO LIEU (CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE,DISPONIBILITE) "
                        "VALUES (:CODE, :NOM_LIEU, :LOCALISATION, :TYPE, :DISPONIBILITE)");
          query.bindValue(":CODE",code_lieu_string );
          query.bindValue(":NOM_LIEU", NOM_LIEU);
          query.bindValue(":LOCALISATION", LOCALISATION);
          query.bindValue(":TYPE", TYPE);
          query.bindValue(":DISPONIBILITE", DISPONIBILITE);
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
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DISPONIBILITE"));

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


bool lieu ::modifier_lieu(int CODE_LIEUM, QString NOM_LIEUM,QString LOCALISATIONM,QString TYPEM,QString DISPOM)
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(CODE_LIEUM);
          query.prepare("UPDATE LIEU SET CODE_LIEU=:CODE_LIEU,NOM_LIEU=:NOM_LIEU,LOCALISATION=:LOCALISATION,TYPE=:TYPE,DISPONIBILITE=:DISPOM WHERE CODE_LIEU=:CODE_LIEU ");

          query.bindValue(":CODE_LIEU",code_lieu_string );
          query.bindValue(":NOM_LIEU", NOM_LIEUM);
          query.bindValue(":LOCALISATION", LOCALISATIONM);
          query.bindValue(":TYPE", TYPEM);
          query.bindValue(":DISPOM", DISPOM);
          return  query.exec();

}

bool lieu::recherche_lieu(int code_lieu_recherche)
{
    QSqlQuery query;
    QString code_lieu_string=QString::number(code_lieu_recherche);
    query.prepare("select from LIEU (CODE_LIEU,NOM_LIEU,LOCALISATION,TYPE,DISPONIBILITE) "
                  "VALUES (:CODE_LIEU, :NOM_LIEU, :LOCALISATION, :TYPE, :DISPONIBILITE)");
    query.bindValue(":CODE_LIEU", code_lieu_string);
    query.bindValue(":NOM_LIEU", NOM_LIEU);
    query.bindValue(":LOCALISATION", LOCALISATION);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":DISPONIBILITE",DISPONIBILITE);
    bool test=query.exec();
//louken saret el requete naamel supprimer
    if(test==true)
    {
        supprimer_lieu(code_lieu_recherche);
    }
    return  test; //sinon exection requete
}



QSqlQueryModel * lieu::afficher_code_lieu_rechercher(QString recherche)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIEU where code_lieu Like '%"+recherche+"%'" ); //Acces au contenu de la table
    return model;
}


QSqlQueryModel * lieu::afficher_nom_lieu_rechercher(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIEU where nom_lieu Like '%"+nom+"%'" ); //Acces au contenu de la table
    return model;
}

QSqlQueryModel * lieu::afficher_localisation_lieu_rechercher(QString localisation)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIEU where localisation Like '%"+localisation+"%'" ); //Acces au contenu de la table
    return model;
}
QSqlQueryModel* lieu::tri_code()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM LIEU ORDER BY CODE_LIEU ASC");
    return model;
}
QSqlQueryModel* lieu::tri_dispo()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM LIEU ORDER BY DISPONIBILITE DESC");
    return model;
}


QString lieu::pdf(int code)
 {
            QSqlQuery qry;QString Info="Lieu inexistant ! ";
            qry.prepare("SELECT * FROM LIEU where CODE_LIEU= :CODE_LIEU");
            qry.bindValue(":CODE_LIEU",code);
            if (qry.exec())
            {
                while(qry.next())
                {
                    QString CODE_LIEU=qry.value(0).toString();
                    QString NOM_LIEU=qry.value(1).toString();
                    QString LOCALISATION=qry.value(2).toString();
                    QString TYPE=qry.value(3).toString();
                    QString DISPONIBILITE=qry.value(4).toString();
                    Info="\t\t\t\t\t Information Sur Lieu \n\t type: \t\t"+ TYPE +"\n\t code: \t\t"+CODE_LIEU+"\n\t nom: \t\t"+NOM_LIEU+"\n\t localisation: \t\t"+LOCALISATION+"\n\t disponibilite: \t\t"+DISPONIBILITE;
                }
            }
            return Info;
 }
int lieu::reserva(int id_evenement,QString type)
{
    int code=0;
    QSqlQuery qry;
    QString lieu;
    qry.prepare("select * from EVENEMENT where ID_EVENEMENT= :id_evenement");
    qry.bindValue(":id_evenement",id_evenement);
    if (qry.exec())
    {
        while(qry.next())
        {
            lieu=qry.value(6).toString();
        }
        QSqlQuery qryy;
        qryy.prepare("select * from LIEU where TYPE= :type and LOCALISATION= :localisation and DISPONIBILITE= :dispo ");
        qryy.bindValue(":type",type);
        qryy.bindValue(":localisation",lieu);
        qryy.bindValue(":dispo","oui");
        if (qryy.exec())
        {
             while(qryy.next())
            {
                code=qryy.value(0).toInt();
            }
             QString code_string=QString::number(code);
             QString id_event_string=QString::number(id_evenement);

             QSqlQuery query;
             query.prepare("Update EVENEMENT set code_lieu= :code_lieu where id_evenement= :id_evenement");
             query.bindValue(":code_lieu", code_string);
             query.bindValue(":id_evenement", id_event_string);
             query.exec();

             QSqlQuery queryy;
             queryy.prepare("Update LIEU set DISPONIBILITE= :dispo where code_lieu = :code_lieu ");
             queryy.bindValue(":code_lieu", code_string);
             queryy.bindValue(":dispo", "non");
             queryy.exec();
        }
    }

    return code;
}
