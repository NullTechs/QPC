#ifndef ITWINDOW_H
#define ITWINDOW_H
#include <QDialog>
#include<QtNetwork/QHostAddress>
#include<QtNetwork/QHostInfo>
#include<QNetworkInterface>
#include<QDnsLookup>
#include<QDir>
#include<QProcess>
#include<QStorageInfo>
#include <QAmbientTemperatureReading>



namespace Ui {
class ItWindow;
}

class ItWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ItWindow(QWidget *parent = 0);
    QString  ohuDNS;

    ~ItWindow();

private:
    Ui::ItWindow *ui;
    QString getMachineName();
    QString getMachineVer();
    const QString GetScope();
    QString getMachineDomain();
    QString ohuLookup();
    QString GetIpv4();
    QString GetIpv6();
    void ExecuteButton();
    QString StorageInfo(int);
    QString GetTempr();




private slots:


   void on_NetStatButton_released();
   void on_RemoteConButton_released();
   void on_ExecuteButton_released();
   void on_PrintersButton_released();
   void on_AddRemButton_released();
   void on_IpConfButton_released();
   void on_NtConButton_released();
};

#endif // ITWINDOW_H
