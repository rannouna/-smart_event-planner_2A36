#ifndef lieu_inter_H
#define lieu_inter_H

#include <QMainWindow>
#include "arduino.h"
#include "lieu.h"
#include <QPainter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include<QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QLabel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {class lieu_inter;}
QT_END_NAMESPACE
class lieu_inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit lieu_inter(QWidget *parent = nullptr);
    ~lieu_inter();

private slots:
    void on_pb_ajouter_lieu_clicked();
    //void on_pushButton_supprimer_clicked();

    void on_pb_supprimer_lieu_clicked();
    void on_pb_modifier_lieu_clicked();

    void on_pb_pdf_lieu_clicked();

    void on_trier_lieu_currentIndexChanged(int index);

    void on_nom_lieu_a_recherche_textChanged(const QString &arg1);

    void on_code_lieu_a_recherche_textChanged(const QString &arg1);

    void on_loc_lieu_a_recherche_textChanged(const QString &arg1);

    void on_tab_lieu_clicked(const QModelIndex &index);


void login_arduino_lieu();

    void on_upload_lieu_clicked();

    void on_reserver_lieu_clicked();

    void on_stat_lieu_clicked();

    void on_recherch_ard_lieu_clicked();


private:
    Ui::lieu_inter *ui;
    lieu LI;
   Arduino A;
      QByteArray data_lieu;
        QString ch="";
};

#endif // lieu_inter_H
