#ifndef SPONSORS_H
#define SPONSORS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class sponsors
{
public :
    sponsors();
    sponsors(QString,QString,QString,QString,QString);

    void setid(QString);
    void setnumero(QString);
    void setnum0(QString);
    void settype(QString);
    void setprix(QString);

    QString get_id();
    QString get_numero();
    QString get_num0();
    QString get_type();
    QString get_prix();



    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool modifier(int);
    QSqlQueryModel * trieid();
    QSqlQueryModel * trienumero();
    QSqlQueryModel * trietype();
    QSqlQueryModel * classification();
    QSqlQueryModel * afficherclassification();

    void recherche(QTableView * table, QString);
    void telechargerPDF();
private:
    QString id,prix,type,numero,num0;
};





#endif // SPONSORS_H
