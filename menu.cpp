#include "menu.h"
#include "ui_menu.h"

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
