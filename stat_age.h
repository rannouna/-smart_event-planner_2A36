#ifndef STAT_AGE_H
#define STAT_AGE_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_age;
}

class stat_age : public QDialog
{
    Q_OBJECT

public:
    explicit stat_age(QWidget *parent = nullptr);
    ~stat_age();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();

private:
    Ui::stat_age *ui;
};

#endif // STAT_AGE_H
