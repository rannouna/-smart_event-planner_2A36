#include "connection.h"
#include <QMessageBox>
Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("projet2A");
db.setUserName("rania");//inserer nom de l'utilisateur
db.setPassword("rania");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeconnection(){db.close(); }
