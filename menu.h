#ifndef MENU_H
#define MENU_H
#include "mainwindow.h"

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_btnemp_clicked();

    void on_btnfact_clicked();

    void on_btnevent_clicked();

    void on_btnspon_clicked();

    void on_btnlieu_clicked();

    void on_btnclient_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
