#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class log;
}

class log : public QDialog
{
    Q_OBJECT

public:
    explicit log(QWidget *parent = nullptr);
    ~log();

private slots:
    void on_pushButton_clicked();

private:
    Ui::log *ui;
    MainWindow menu ;
};

#endif // LOG_H
