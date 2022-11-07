#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 Connection c;
    bool test=c.createconnexion();
    MainWindow w;

    if(test)
    {
    w.show();
    QMessageBox::information(nullptr, QObject::tr("Connexion"),QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"), QObject::tr("connection failed.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
