#include "log.h"
#include "ui_log.h"
#include "QMessageBox"
#include <QWidget>

log::log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);
}

log::~log()
{
    delete ui;
}

void log::on_pushButton_clicked()
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
