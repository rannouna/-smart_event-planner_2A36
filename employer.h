#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class Employer
{
public:
    //constracteures
    Employer(QString,QString,QString,QString,QString,QString);
    //setters
    void setid_employer(QString);
    void setdate_de_naissance(QString);
    void setnom(QString);
    void setprenom(QString);
    void setposte(QString);
    void setnum(QString);
    //getters
    QString getid_employer();
    QString getdate_de_naissance();
    QString getnom();
    QString getprenom();
    QString getposte();
    QString getnum();
    //base de donner
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

     bool modifier(int);

     QSqlQueryModel * trieid_employer();
     QSqlQueryModel * trienom();
     QSqlQueryModel * trieprenom();
     void recherche(QTableView * table, QString);
     void telechargerPDF();
     
     QSqlQuery login(QString,QString);
     QSqlQuery logincard(QString);


    Employer();
private:

    QString nom,prenom,poste,date_de_naissance,id_employer,num;
};

#endif // EMPLOYER_H
