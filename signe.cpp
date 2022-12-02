#include "signe.h"
#include "ui_signe.h"
#include <QMessageBox>
#include <QPixmap>
signe::signe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signe)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

signe::~signe()
{
    delete ui;
}

void signe::update_label()
{
    data=A.read_from_arduino();

    qDebug() << data;

        c+=data;

    qDebug()<<c;

    if( c.length()==12)
    {
        QSqlQuery query;
        query =tmpE.logincard(c);
        if(query.exec())
        {
            if(query.next())
            {
                A.write_to_arduino("1");

                signe::close();
                menu *m = new menu();
                m->show();

            }
            else
            {
                QMessageBox::warning(this,"Login", "CARD NOT FOUND");
            }
        }

    }


    if(c.length()>=12)
    {
        t=0;
        c="";
    }

}

void signe::on_pushButton_clicked()
{
    QSqlQuery query;

    QString username=ui->lineEdit_user->text();
    QString password=ui->lineEdit_2_password->text();

    query =tmpE.login(username,password);
    if(query.exec())
    {
        if(query.next())
        {
            signe::close();
            menu *m = new menu();
            m->show();

        }
        else
        {
            QMessageBox::warning(this,"Login", "Username and password is not correct");
        }
    }



}
