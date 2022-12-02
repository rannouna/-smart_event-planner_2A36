#include "employer.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QPdfWriter>
#include<QPainter>

Employer::Employer()
{

     id_employer="";date_de_naissance="";poste="";nom="";prenom="";num="";
}



void Employer::setnom(QString nom){this->nom=nom;}
void Employer::setprenom(QString prenom){this->prenom=prenom;}
void Employer::setposte(QString poste){this->poste=poste;}
void Employer::setid_employer(QString id_employer){this->id_employer=id_employer;}
void Employer::setdate_de_naissance(QString date_de_naissance){this->date_de_naissance=date_de_naissance;}
void Employer::setnum(QString num){this->num=num;}

QString Employer::getid_employer(){return id_employer;}
QString Employer::getdate_de_naissance(){return date_de_naissance;}
QString Employer::getnom(){return nom;}
QString Employer::getprenom(){return prenom;}
QString Employer::getposte(){return poste;}
QString Employer::getnum(){return num;}

bool Employer::ajouter(){
    QSqlQuery query;
    //QString res= QString::number( id_employer);
    query.prepare("INSERT INTO EMPLOYE (NOM,PRENOM,DATE_DE_NAISSANCE,POSTE,ID_EMPLOYER) " "values (:nom, :prenom, :date, :poste, :id_employer)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date_de_naissance);
    query.bindValue(":poste",poste);
    query.bindValue(":id_employer",id_employer);
    return query.exec();
}

//QSqlQueryModel * Employer
bool Employer::supprimer(int id_employer)
    {
        QSqlQuery query;
        QString res= QString::number( id_employer);
        query.prepare("delete from EMPLOYE where ID_EMPLOYER= :id_employer");
        query.bindValue(":id_employer",res);
        return query.exec();

    }
QSqlQueryModel * Employer::afficher()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from EMPLOYE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMPLOYER"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DE_NAISSANCE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("POSTE"));


        return model;


    }

/*bool Employer::update(QString nom,QString id_employer)
    {
      QSqlQuery query;
      query.prepare("update Employer set NOM_EMP='"+nom+"' ,ID-EMP='"+id_employer+"'");
      return query.exec();
    }
*/

bool Employer::modifier(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("update EMPLOYE set NOM=:nom,PRENOM=:prenom,DATE_DE_NAISSANCE=:date_de_naissance,POSTE=:poste,ID_EMPLOYER=:id_employer where ID_EMPLOYER=:num");
query.bindValue(":num",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":date",date_de_naissance);
query.bindValue(":poste",poste);
query.bindValue(":id_employer",id_employer);
return    query.exec();
}


QSqlQueryModel * Employer::trieid_employer()

 {

     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM EMPLOYE ORDER BY id_employer");

     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id_employer"));

     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("date_de_naissance"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("poste"));

     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("nom"));

     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("prenom"));








     return model;

 }
QSqlQueryModel * Employer::trienom()

 {

     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM EMPLOYE ORDER BY NOM");

     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id_employer"));

     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("date_de_naissance"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("poste"));

     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("nom"));

     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("prenom"));






     return model;

 }
QSqlQueryModel * Employer::trieprenom()

 {

     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM EMPLOYE ORDER BY PRENOM");

     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id_employer"));

     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("date_de_naissance"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("poste"));

     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("nom"));

     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("prenom"));





     return model;

 }

void Employer::recherche(QTableView * table, QString rech)

{

    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;

        query->prepare("select * from EMPLOYE where NOM like '%"+rech+"%' or PRENOM like '%"+rech+"%' or POSTE like '%"+rech+"%';");

        query->exec();

        model->setQuery(*query);

        table->setModel(model);

        table->show();

}
void  Employer::telechargerPDF(){

                      QPdfWriter pdf("C:/Users/garal/OneDrive/Bureau/Export PDF/PDF.pdf");



                      QPainter painter(&pdf);
                     int i = 4000;



                          painter.setPen(Qt::blue);
                           painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                          painter.drawText(2000,1500,"LISTES DES EMPLOYE");
                          painter.setPen(Qt::black);
                          painter.drawRect(0,2700,9600,500);
                          painter.setFont(QFont("Calibri",14,QFont::Bold));
                          painter.drawText(200,3000,"id_employer");
                          painter.drawText(1800,3000,"nom");
                          painter.drawText(3100,3000,"prenom");
                          painter.drawText(4900,3000,"date_de_naissance");
                          painter.drawText(6800,3000,"poste");




                          QSqlQuery query;

                          query.prepare("select * from EMPLOYE");
                          query.exec();
                          while (query.next())
                          {
                                 painter.setFont(QFont("Calibri",13));
                              painter.drawText(200,i,query.value(1).toString());
                              painter.drawText(1800,i,query.value(0).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(4900,i,query.value(3).toString());
                              painter.drawText(6900,i,query.value(4).toString());




                             i = i + 500;
                          }
}



QSqlQuery Employer::login(QString nom,QString mdp)
{
    QSqlQuery query;
    query.prepare("select * from ADMIN where NOMUSER= '"+nom+"' and mdp='"+mdp+"'");
    query.exec();
    return query;
}

QSqlQuery Employer::logincard(QString CARD)
{
    QSqlQuery query;
    query.prepare("select * from ADMIN where CARD= '"+CARD+"' ");
    query.exec();
    return query;
}








