#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>

#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>




#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_e_ajouter_clicked()
{
        ptmp.set_id(ui->lineEdit_id_e->text().toInt());
        ptmp.set_nbV(ui->lineEdit_nbv_e->text().toInt());
        ptmp.set_nom(ui->lineEdit_nom_e->text());
        ptmp.set_spon(ui->lineEdit_spon_e->text());

        bool test=ptmp.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajouté avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


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
                //ptmp.notification_suppProduit();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("error.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_m->setModel(ptmp.afficher());
}

