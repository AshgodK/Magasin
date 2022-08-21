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

private:
    Ui::MainWindow *ui;

    magasin ptmp;
};
#endif // MAINWINDOW_H
