#include "client.h"

client::client()
{

}

client::client(int i,QString s1 ,QString s2,QString s3 ,QString s4 ,QString s5 ){
    age=i;
    cin=s1;
    nom=s2;
    adresse=s3;
    mail=s4;
    code=s5;
}


bool client::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CLIENT (cin, NOM_CLIENT,age,adresse,mail,ID_EVENENEMT) "
                        "VALUES (:cin, :nom, :age,:adresse,:mail,:code)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom",nom); //remplir la valeur d'une maniere securisée
    query.bindValue(":age", age);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":code", code);

    return    query.exec();

}

bool client::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE CLIENT SET NOM_CLIENT= :nom ,age= :age ,adresse= :adresse,mail= :mail ,ID_EVENENEMT= :code "
                  "where cin= :cin");
    query.bindValue(":cin", selected);
    query.bindValue(":nom",nom); //remplir la valeur d'une maniere securisée
    query.bindValue(":age", age);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":code", code);

    return    query.exec();

}

 QSqlQueryModel * client::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM CLIENT");

     return modal;

 }
  bool client::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from CLIENT where cin = :sel ");
      query.bindValue(":sel", selected);
      return    query.exec();


  }
