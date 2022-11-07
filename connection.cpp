#include<QSqlDatabase>
#include "connection.h"

Connection::Connection(){}
/////////////////test
bool Connection::createconnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("gestion_des_evenement");
    db.setUserName("tasnim");
    db.setPassword("SYSTEM");

    if(db.open())
        test=true;
    return test;
}

void Connection::closeconnexion()
{

    db.close();
}
