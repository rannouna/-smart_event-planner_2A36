#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"EVENEMENT.h"
#include <QMainWindow>
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

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_modifier_clicked();
    void on_ajouter_clicked();
    void on_supprimer_clicked();

    void on_rechercher_button_clicked();
    void on_radioButton_croissant_clicked();

    void on_radioButton_dcroissant_clicked();
    void on_statsmed_clicked();
        void on_btn_imp_clicked();
private:
    Ui::MainWindow *ui;
    EVENEMENT Etmp;
};

#endif // MAINWINDOW_H
