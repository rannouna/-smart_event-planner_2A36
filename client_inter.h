#ifndef CLIENT_INTER_H
#define CLIENT_INTER_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>

#include "client.h"
#include "smtp.h"
#include "stat_age.h"

namespace Ui {
class client_inter;
}

class client_inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit client_inter(QWidget *parent = nullptr);
    ~client_inter();
    client tmp;
    QSortFilterProxyModel *proxy;

    QString cin() const ;
    QString nom() const ;
    QString adresse() const;
    QString mail() const ;
    int age() const;
    QString code() const ;

    void fill_form(QString);

    void show_tables();


private slots:
    void on_Add_clicked();

    void on_Update_clicked();

    void on_Delete_clicked();

    void on_stat_clicked();

    void on_Export_pdf_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_tableau_clicked(const QModelIndex &index);

    void on_tableau_doubleClicked(const QModelIndex &index);

    void on_recherche_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::client_inter *ui;
    int sel_col=-1;
        QString selected="",mail_pass="211JFT8269";
        QStringList files;
        stat_age *s;

};

#endif // CLIENT_INTER_H
