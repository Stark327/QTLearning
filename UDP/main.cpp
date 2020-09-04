#include "mainwindow.h"

#include <QApplication>
#include <iostream>


QUdpSocket *socket;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QByteArray array;
    w.show();

    cout<<"hello"<<endl;
//    socket = new QUdpSocket();
//    socket->bind(QHostAddress(QHostAddress::Any),50002);
//    while(!socket->hasPendingDatagrams());
//    array.resize(socket->pendingDatagramSize());
//    socket->readDatagram(array.data(), array.size());
//    qDebug()<<array.data();
//    socket->writeDatagram("hello",QHostAddress(QHostAddress::Broadcast),50003);



    return a.exec();
}


