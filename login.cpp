#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
        QString username = ui->userline->text();
        QString password = ui->passwordline->text();

        if (username == "khalil" && password == "khalil")
        {
            hide();
            menu.show();
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                       QObject::tr("INVALID USERNAME OR PASSWORD.\nClick Cancel to exit."), QMessageBox::Ok);
        }

}
