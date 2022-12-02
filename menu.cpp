#include "menu.h"
#include "ui_menu.h"
#include "facteur_inter.h"
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
