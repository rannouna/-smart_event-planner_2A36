#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "lieu.h"
#include <iostream>
#include <QString>
#include <QtSql>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection(); //etablir la connection
    MainWindow w;

    if(test)
    {
      w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();






   /* QApplication app( argc, argv );

    // Set up database
    QString dbName( "Projet2A.db3" );
    QFile::remove( dbName ); // delete sqlite file if it exists from a previous run
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( dbName );
    db.open();
    QSqlQuery query = QSqlQuery( db );
    query.exec( "CREATE TABLE IF NOT EXISTS imgTable ( filename TEXT, imagedata BLOB )" );

    // Generate an image (in this case a screenshot) and store it in a QByteArray
    QScreen *screen = app.primaryScreen();
    QPixmap inPixmap = screen->grabWindow( 0 );
    QByteArray inByteArray;
    QBuffer inBuffer( &inByteArray );
    inBuffer.open( QIODevice::WriteOnly );
    inPixmap.save( &inBuffer, "PNG" ); // write inPixmap into inByteArray in PNG format

    // Alternatively, load an image file directly into a QByteArray
    // QFile file("screenshot.png");
    // if (!file.open(QIODevice::ReadOnly)) return;
    // QByteArray inByteArray = file.readAll();

    // Insert image bytes into the database
    // Note: make sure to wrap the :placeholder in parenthesis
    query.prepare( "INSERT INTO imgTable (filename, imagedata) VALUES ('Users\felah\Downloads\picture', :imageData)" );
    query.bindValue( ":imageData", inByteArray );
    if( !query.exec() )
        qDebug() << "Error inserting image into table:\n" << query.lastError();

    // Get image data back from database
    if( !query.exec( "SELECT imagedata from imgTable" ))
        qDebug() << "Error getting image from table:\n" << query.lastError();
    query.first();
    QByteArray outByteArray = query.value( 0 ).toByteArray();
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData( outByteArray );
    db.close();

    // Display image
    QLabel myLabel;
    myLabel.setPixmap( outPixmap );
    myLabel.show();

    //return app.exec();*/
}


