#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDesktopServices>
#include <QMainWindow>
#include"itwindow.h"
#include<QString>
#include<QUrl>
#include<QSysInfo>
#include<QDebug>
#include<QtNetwork/QHostAddress>
#include<QtNetwork/QHostInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_4_released();

    void on_pushButton_3_released();

    void on_pushButton_6_released();

    void on_pushButton_7_released();







    void on_pushButton_8_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
