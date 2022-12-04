#include "connection.h"
#include <QMessageBox>
Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
 db.setDatabaseName("source_projet2A");
 db.setUserName("bechir");//inserer nom de l'utilisateur
 db.setPassword("1234");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;





    return  test;
}
void Connection::closeconnection(){db.close(); }
