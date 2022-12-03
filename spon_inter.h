#ifndef SPON_INTER_H
#define SPON_INTER_H

#include "sponsor.h"
#include "arduino.h"

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class spon_inter;
}

class spon_inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit spon_inter(QWidget *parent = nullptr);
    ~spon_inter();
private slots:

   void on_pb_ajouter_3_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_le_id_2_textChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_ajouter_5_clicked();

    void update_label();

    void update_label2();

private:
    Ui::spon_inter *ui;
    sponsors etmp;
    Arduino A;

};

#endif // SPON_INTER_H
