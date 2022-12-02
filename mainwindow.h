#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<employer.h>
#include <QMainWindow>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pb_ajouter_clicked();

    void on_bt_supp_clicked();

    void on_pb_modifier_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_ajouter_3_clicked();
  void update_label();

private:
    Ui::MainWindow *ui;
    Employer etmp;
    QByteArray data ;
    Arduino A;
    QString c="";
    int t=0;

};
#endif // MAINWINDOW_H
