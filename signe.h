#ifndef SIGNE_H
#define SIGNE_H

#include <QDialog>
#include "menu.h"
#include "employer.h"
#include "arduino.h"

namespace Ui {
class signe;
}

class signe : public QDialog
{
    Q_OBJECT

public:
    explicit signe(QWidget *parent = nullptr);
    ~signe();

private slots:
    void on_pushButton_clicked();

    void update_label();

private:
    Ui::signe *ui;
    MainWindow *mainwindow;
    Employer tmpE;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
    int t=0;
    QString c="";
};

#endif // SIGNE_H
