#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>

#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>
#include <QPainter>
#include <QPdfWriter>



#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_e_ajouter_clicked()
{
        ptmp.set_id(ui->lineEdit_id_e->text().toInt());
        ptmp.set_sur(ui->lineEdit_spon_e->text().toInt());
        ptmp.set_nom(ui->lineEdit_nom_e->text());
        ptmp.set_adr(ui->lineEdit_nbv_e->text());

        bool test=ptmp.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajouté avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ptmp.notification_ajoutmagasin();


    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("error.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_m->setModel(ptmp.afficher());


}



void MainWindow::on_pushButton_a_m_clicked()
{
    ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_del_m_clicked()
{
    int id_del;
            id_del=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),0)).toInt();
            bool test=ptmp.supprimer(id_del);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("supprimé avec succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ptmp.notification_suppmagasin();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("error.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_g_m_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_g_p_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_m_m_clicked()
{
    int id_up;
    id_up=ui->tableView_m->model()->data(ui->tableView_m->model()->index(ui->tableView_m->currentIndex().row(),0)).toInt();
    ptmp.set_sur(ui->lineEdit_spon_e->text().toInt());
    ptmp.set_nom(ui->lineEdit_nom_e->text());
    ptmp.set_adr(ui->lineEdit_nbv_e->text());

    bool test=ptmp.modifier(id_up);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("modifie avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ptmp.notification_modifmagasin();

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_id_textChanged()
{
    if(ui->lineEdit_sea_id->text()!="")
        {
            QString a=ui->lineEdit_sea_id->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (id_m LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_nom_textChanged()
{
    if(ui->lineEdit_sea_nom->text()!="")
        {
            QString a=ui->lineEdit_sea_nom->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (nom LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_lineEdit_sea_sur_textChanged()
{
    if(ui->lineEdit_sea_sur->text()!="")
        {
            QString a=ui->lineEdit_sea_sur->text();
            ui->tableView_m->setModel(ptmp.displayClause("WHERE (surface LIKE '%"+a+"%') "));
        }
        else
            ui->tableView_m->setModel(ptmp.afficher());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_id());
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_nom());
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView_m->setModel(ptmp.tri_sur());
}


void MainWindow::on_pushButton_m_pdf_clicked()
{
    QPdfWriter pdf("E:/qtprojects/untitled1/Pdfmagasin.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3300,1200,"Liste Des Magasins");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(1300,3300,"ID_M");
        painter.drawText(2600,3300,"NOM");
        painter.drawText(3900,3300,"ADRESSE");
        painter.drawText(5200,3300,"SURFACE");




        QSqlQuery query;
        query.prepare("select * from MAGASIN");
        query.exec();
        while (query.next())
        {
            painter.drawText(1300,i,query.value(0).toString());
            painter.drawText(2600,i,query.value(1).toString());
            painter.drawText(3900,i,query.value(2).toString());
            painter.drawText(5200,i,query.value(3).toString());



            i = i +500;
        }
        ptmp.notification_pdf();
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("E:/qtprojects/untitled1/Pdfmagasin.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

