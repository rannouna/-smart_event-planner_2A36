#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lieu.h"
#include <QPainter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include<QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    //void on_pushButton_supprimer_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();

    void on_pb_pdf_clicked();

    void on_trier_currentIndexChanged(int index);

    void on_nom_lieu_a_recherche_textChanged(const QString &arg1);

    void on_code_lieu_a_recherche_textChanged(const QString &arg1);

    void on_loc_lieu_a_recherche_textChanged(const QString &arg1);

    void on_tab_lieu_clicked(const QModelIndex &index);




    void on_upload_clicked();

    void on_reserver_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    lieu LI;
};

#endif // MAINWINDOW_H
