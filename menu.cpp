#include "menu.h"
#include "ui_menu.h"
#include "facteur_inter.h"
#include "spon_inter.h"
#include "event_inter.h"
#include "lieu_inter.h"
#include "client_inter.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_btnemp_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();

}

void menu::on_btnfact_clicked()
{
    facteur_inter *fac = new facteur_inter();
    fac->show();

}

void menu::on_btnevent_clicked()
{
    event_inter *eve = new event_inter();
    eve->show();

}

void menu::on_btnlieu_clicked()
{
    lieu_inter *lieux = new lieu_inter();
    lieux->show();

}


void menu::on_btnspon_clicked()
{
    spon_inter *spon = new spon_inter();
    spon->show();

}

void menu::on_btnclient_clicked()
{
    client_inter *cli = new client_inter();
    cli->show();

}
