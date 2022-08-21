#ifndef MAGASIN_H
#define MAGASIN_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class magasin
{
public:
    magasin();
    magasin(int,int,QString,QString);
    int get_id(){return id_m;}
    int get_sur(){return surface;}
    QString get_nom(){return nom;}
    QString get_adresse(){return adresse;}

    //Setters
    void set_id(int a){id_m=a;}
    void set_nbV(int a){surface=a;}
    void set_nom(QString b){nom=b;}
    void set_spon(QString f){adresse=f;}


   //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *tri_nbV();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *displayClause(QString cls);
    void notification_ajoutProduit();
    void notification_suppProduit();
    void notification_modifProduit();
    void notification_pdf();


private:
 int id_m;
 int surface;
 QString nom;
 QString adresse;

};

#endif // MAGASIN_H
