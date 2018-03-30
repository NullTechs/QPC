#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    MainWindow::close();
}

void MainWindow::on_pushButton_2_released()
{

    QDesktopServices::openUrl(QUrl("https://portal.office.com", QUrl::TolerantMode));

}

void MainWindow::on_pushButton_4_released()
{
     QDesktopServices::openUrl(QUrl("https://inside.onehopeunited.org"));
}

void MainWindow::on_pushButton_3_released()
{
    QDesktopServices::openUrl(QUrl("https://onehopeunited.zendesk.com/hc/en-us/requests/new"));
}



void MainWindow::on_pushButton_6_released()
{
    QDesktopServices::openUrl(QUrl("https://www.yammer.com/onehopeunited.org/?show_login=true"));
}

void MainWindow::on_pushButton_7_released()
{
    QDesktopServices::openUrl(QUrl("https://ew22.ultipro.com/Login.aspx?ReturnUrl=%2f"));
}






void MainWindow::on_pushButton_8_released()
{
 ItWindow* newWin =new ItWindow;
 newWin->setModal(true);
 newWin->setWindowTitle("IT Tools");
 newWin->show();
 QApplication::setStyle("fusion");

}
