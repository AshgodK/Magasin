#include "magasin.h"

magasin::magasin()
{

}
magasin::magasin(int a,int b,QString c,QString d)
{
    id_m=a;
    surface=b;
    nom=c;
    adresse=d;
}

bool magasin::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_m);
    QString res1 = QString::number(surface);

    query.prepare("INSERT INTO magasin(id_m,surface,nom,adresse)""VALUES (:id_m,:surface,:nom,:adresse)");
    query.bindValue(":id_m",res);
    query.bindValue(":surface",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);


    return query.exec();
}


QSqlQueryModel * magasin::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM magasin");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_m"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("surface"));

    return model;
}


bool magasin::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM magasin WHERE id_m = :id");
    query.bindValue(":id",res);
    return query.exec();
}
