#ifndef CLIENT_H
#define CLIENT_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,QString,QString,QString,QString,QString);


    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);

      int age;
      QString cin, mail, adresse, code,nom;
};

#endif // CLIENT_H
