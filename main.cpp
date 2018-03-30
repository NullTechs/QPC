#include "mainwindow.h"
#include <QApplication>
#include"itwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");
    MainWindow w;
    w.show();
    w.setWindowTitle("One Hope United");


    return a.exec();
}
