#ifndef FACTEUR_INTER_H
#define FACTEUR_INTER_H

#include <QMainWindow>
#include <facteur.h>
 #include "piechartwidget.h"
namespace Ui {
class facteur_inter;
}

class facteur_inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit facteur_inter(QWidget *parent = nullptr);
    ~facteur_inter();
private slots:
    void on_ajout_button_clicked();


    void on_button_supp_clicked();

    void on_modifier_button_clicked();

    void on_pardate_clicked();

    void on_partype_clicked();

    void on_actualiser_clicked();

    void on_recherche_clicked();

    void on_exel_clicked();


    void on_tableView222_activated(const QModelIndex &index);


    void on_clear_clicked();

    void on_listView_activated(const QModelIndex &index);

    void on_actualiser_stat_clicked();

private:
    Ui::facteur_inter *ui;
    Facteur f ;
    PieChartWidget p ;

};

#endif // FACTEUR_INTER_H
