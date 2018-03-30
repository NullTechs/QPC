#include "itwindow.h"
#include "ui_itwindow.h"

ItWindow::ItWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItWindow)
{
    ui->setupUi(this);
    ui->MachNameLabel->setText(getMachineName());
    ui->MachVerLabel->setText(getMachineVer());
    ui->MachCPU->setText(QSysInfo::currentCpuArchitecture());
    ui->TempretureLabel->setText(GetTempr());
    ui->IPv4Label->setText(GetIpv4());
    ui->IPv6Label->setText(GetIpv6());
    ui->DomainLabel->setText(getMachineDomain());
    ui->OhuLabel->setText(ohuLookup());
    ui->DriveNameLabel->setText(StorageInfo(1));
    ui->FreeSpaceLabel->setText(StorageInfo(2));
    //ui->Sysmodel->setText(QSysInfo
    ui->TotalSpace->setText(StorageInfo(3));
    ui->FileSystemLabel->setText(StorageInfo(4));
}

ItWindow::~ItWindow()
{
    delete ui;
}




//--------------------------------- IT Tools---------------------------------------




// ******** Machine Name ********


QString ItWindow::getMachineName()
    {

    return QSysInfo::machineHostName();

    }





//********* Machine Version ********

QString ItWindow::getMachineVer()
{

    return QSysInfo::prettyProductName();


}

const QString ItWindow::GetScope()

{
    QHostAddress mo;
    QString scope= mo.scopeId();
    return scope;
}





//******** Domain Name ********

QString ItWindow::getMachineDomain()
{

    QHostInfo hostinfo;
    QString DomainName=hostinfo.localDomainName();
    if (DomainName=="")
        return "No domain found !";
    else

        return DomainName;
}



//******** Website Ip Lookup ********

QString ItWindow::ohuLookup()
{

    QHostInfo hostInfo = QHostInfo::fromName("onehopeunited.org");
    if (hostInfo.error() != QHostInfo::NoError)
    {
        qDebug() << "Lookup failed:" << hostInfo.errorString();
    }
    foreach (QHostAddress hostAdd, hostInfo.addresses())
    {
        qDebug() << "Found address:" << hostAdd.toString();
        ohuDNS = hostAdd.toString();
    }
    if(ohuDNS=="104.196.195.217")
        return "104.196.195.217  Passed !! Our website is up and running";
    else
        return "Couldn't be resolved !!Sorry";


}



//******** IPv4 Address ********


QString ItWindow::GetIpv4()
{

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString NewInterface;

     for(int nIter=0; nIter<list.count(); nIter++)

      {
          if(!list[nIter].isLoopback())
              if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol)
              NewInterface= list[nIter].toString();

      }

    return NewInterface;
}


//******** IPv6 Address ********



QString ItWindow::GetIpv6()
{

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString NewInterface;

     for(int nIter=0; nIter<list.count(); nIter++)

      {
          if(!list[nIter].isLoopback())
              if (list[nIter].protocol() == QAbstractSocket::IPv6Protocol)
              NewInterface= list[nIter].toString();

      }

    return NewInterface;
}


//*********Storage Info**********

QString ItWindow::StorageInfo(int Requested)
{


         QString ReturningVal;
         qint64 temp;
         QStorageInfo CurrentStorage = QStorageInfo::root();

         switch (Requested)
         {
         case 1:
             ReturningVal= CurrentStorage.displayName();
             break;

         case 2:

             temp=CurrentStorage.bytesFree()/1000/1000;
             ReturningVal= QString::number(temp)+" MB";
             break;

         case 3:


             temp=CurrentStorage.bytesTotal()/1000/1000;
             ReturningVal= QString::number(temp)+" MB";
             break;


         case 4:
             ReturningVal= CurrentStorage.fileSystemType();



         default:
             break;
         }




    return ReturningVal;
}



















//*******Execute Button****************

void ItWindow::ExecuteButton()
{

 int CurrentChoice = ui->QuickComDB->currentIndex();
 qDebug()<<CurrentChoice;

 if(CurrentChoice==0)
     system("cmd/k ipconfig /flushdns");
 else if (CurrentChoice==1)
     system("cmd/k Shutdown/r");
 else if (CurrentChoice==2)
     system("%windir%\\System32\\cmd.exe");


}



QString ItWindow::GetTempr()
{


  QAmbientTemperatureReading ReadTemp;
  qreal tempreture=ReadTemp.temperature();


  QString ReturningValue= QString::number(tempreture);
  qDebug()<<ReturningValue;
  if(ReturningValue=="0")
      return "Not Supported";
  else
  return ReturningValue;



}








void ItWindow::on_NetStatButton_released()
{
     system("cmd /k NETSTAT -a");
}

void ItWindow::on_RemoteConButton_released()
{
    system("mstsc");
}

void ItWindow::on_ExecuteButton_released()
{
    ExecuteButton();
}

void ItWindow::on_PrintersButton_released()
{
        system("control printers");
}

void ItWindow::on_AddRemButton_released()
{
    system("control /name Microsoft.ProgramsAndFeatures");
}

void ItWindow::on_IpConfButton_released()
{
    system("cmd /k ipconfig/all");
}

void ItWindow::on_NtConButton_released()
{
    system("control ncpa.cpl");
}
