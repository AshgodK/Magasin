#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "magasin.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
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
    void on_pushButton_e_ajouter_clicked();

    void on_pushButton_a_m_clicked();

    void on_pushButton_del_m_clicked();

    void on_pushButton_g_m_clicked();

    void on_pushButton_g_p_clicked();

    void on_pushButton_clicked();

    void on_pushButton_m_m_clicked();

    void on_lineEdit_sea_id_textChanged();

    void on_lineEdit_sea_nom_textChanged();

    void on_lineEdit_sea_sur_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_m_pdf_clicked();

private:
    Ui::MainWindow *ui;

    magasin ptmp;
};
#endif // MAINWINDOW_H
