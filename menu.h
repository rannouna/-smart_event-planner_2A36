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

private:
    Ui::menu *ui;
};

#endif // MENU_H
