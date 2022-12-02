#ifndef EVENT_INTER_H
#define EVENT_INTER_H

#include <QMainWindow>
#include"EVENEMENT.h"
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include <QMessageBox>
#include <QDialog>

#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include "arduino.h"

namespace Ui {
class event_inter;
}

class event_inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit event_inter(QWidget *parent = nullptr);
    ~event_inter();
private slots:

    void on_modifier_clicked();
    void on_ajouter_clicked();
    void on_supprimer_clicked();

    void on_rechercher_button_clicked();
    void on_radioButton_croissant_clicked();

    void on_radioButton_dcroissant_clicked();
    void on_statsmed_clicked();
        void on_btn_imp_clicked();

        void on_afficher_doubleClicked(const QModelIndex &index);

        void on_calendarWidget_clicked(const QDate &date);

        void on_btn_calculer_clicked();

        void update_label();

private:
    Ui::event_inter *ui;
    EVENEMENT Etmp;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire


};

#endif // EVENT_INTER_H
