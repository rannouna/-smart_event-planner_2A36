#include "sponsor.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QPdfWriter>
#include<QPainter>
sponsors::sponsors()
{
    id="";
    prix="";
    type="";
    numero="";
    num0="";
}
 //clients::clients(QString cin,QString nom,QString prenom,QString destination,QString datedenaissance,QString numero,QString num0)
 //;{this->cin=cin; this->nom=nom;this->prenom=prenom;this->destination=destination;this->datedenaissance=datedenaissance;this->numero=numero;this->num0=num0}
 QString sponsors::get_id(){return id;}
 QString sponsors::get_type(){return type;}
 QString sponsors::get_prix(){return prix;}
 QString sponsors:: get_numero(){return numero;}
 QString sponsors:: get_num0(){return num0;}

 void sponsors::setid(QString id){this->id=id;}
 void sponsors::setprix(QString prix){this->prix=prix;}
 void sponsors::settype(QString type){this->type=type;}
 void sponsors::setnumero(QString numero){this->numero=numero;}
 void sponsors::setnum0(QString n){num0=n;}
 bool sponsors::ajouter()
 // this->num0=num0
 {
     QSqlQuery query;



           query.prepare("insert into SPONSOR (ID_C, PRIX_C, TYPE_C,NUMERO_C) "
                         "values (:id, :prix, :type, :numero)");
           query.bindValue(":id", id);
           query.bindValue(":prix", prix);
           query.bindValue(":type", type);
           query.bindValue(":numero", numero);
           return query.exec();
 }
 bool sponsors::supprimer(int id)
 {
     QSqlQuery query;
     QString res=QString::number(id);
     query.prepare("delete from SPONSOR where ID_C= :id");
     query.bindValue(":id",res);
     return query.exec();
 }
 QSqlQueryModel * sponsors::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel () ;
     model->setQuery("select * from SPONSOR");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));
     return model;

 }
 bool sponsors::modifier(int num0)
 {
     QSqlQuery query;
     QString res=QString::number(num0);

           query.prepare("update SPONSOR set ID_C=:id, PRIX_C=:prix,TYPE_C=:type,NUMERO_C=:numero Where ID_C=:num0 ");
           query.bindValue(":num0",res);
           query.bindValue(":id", id);
           query.bindValue(":prix", prix);
           query.bindValue(":type", type);
           query.bindValue(":numero", numero);


           return query.exec();
 }
 QSqlQueryModel * sponsors::trieid()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM SPONSOR ORDER BY ID_C");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));

     return model;
 }
 QSqlQueryModel * sponsors::trienumero()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM SPONSOR ORDER BY NUMERO_C");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));

     return model;
 }
 QSqlQueryModel * sponsors::trietype()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM SPONSOR ORDER BY TYPE_C");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));

     return model;
 }
 void sponsors::recherche(QTableView * table, QString rech)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery *query=new QSqlQuery;
         query->prepare("select * from SPONSOR where ID_C like '%"+rech+"%';");
         query->exec();
         model->setQuery(*query);
         table->setModel(model);
         table->show();
 }
 void  sponsors::telechargerPDF(){

                      QPdfWriter pdf("C:/Users/garal/OneDrive/Bureau/2A36/projet c++/gestion_employer/PDF.pdf");



                      QPainter painter(&pdf);
                     int i = 4000;



                          painter.setPen(Qt::blue);
                           painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                          painter.drawText(2000,1500,"LISTES DES SPONSORS");
                          painter.setPen(Qt::black);
                          painter.drawRect(0,2700,6500,500);
                          painter.setFont(QFont("Calibri",14,QFont::Bold));
                          painter.drawText(200,3000,"id");
                          painter.drawText(1800,3000,"prix");
                          painter.drawText(3100,3000,"type");
                          painter.drawText(4900,3000,"numero");

                         // QString s = QDate::currentDate().toString();
                          //painter.setFont(QFont("Calibri",15,QFont::Bold));
                         // painter.drawText(4000,2000,s);

                          QSqlQuery query;

                          query.prepare("select * from SPONSOR");
                          query.exec();
                          while (query.next())
                          {
                                 painter.setFont(QFont("Calibri",13));
                              painter.drawText(200,i,query.value(1).toString());
                              painter.drawText(1800,i,query.value(0).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(4900,i,query.value(3).toString());



                             i = i + 500;
                          }}

 QSqlQueryModel * sponsors::classification()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM SPONSOR ORDER BY PRIX_C");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));

     return model;
 }

 QSqlQueryModel * sponsors::afficherclassification()
 {
     QSqlQueryModel * model=new QSqlQueryModel () ;
     model->setQuery("select * from SPONSOR");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));
     return model;

 }

