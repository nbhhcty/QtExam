#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new QTcpServer();

    //连接信号槽
    connect(server,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);

    this->on_pushButton_Listen_clicked();
}

MainWindow::~MainWindow()
{
    server->close();
    server->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_Listen_clicked()
{
    unsigned short port = 9527;
    if(!server->listen(QHostAddress::Any, port))
    {
        qDebug()<<server->errorString();
        return;
    }
    qDebug()<< "Listen succeessfully!";
}

void MainWindow::on_pushButton_Send_clicked()
{
    //获取文本框内容并以ASCII码形式发送
//    socket->write("server send");
//    socket->flush();
}

void MainWindow::server_New_Connect()
{
    //获取客户端连接
    QTcpSocket* socket = server->nextPendingConnection();
    this->m_clientSocketLst.append(socket);

    //连接QTcpSocket的信号槽，以读取新数据
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);
    //一个socket断开连接就从底层链表中删除对应的对象
    qDebug() << "A Client connect!";
}

void MainWindow::socket_Read_Data()
{
    QTcpSocket* socket = (QTcpSocket*)QObject::sender();  // 获得是哪个socket收到了消息
    QByteArray buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        qDebug() << socket->socketDescriptor() << "读取到数据!" + tr(buffer);
    }
}

void MainWindow::socket_Disconnected()
{
    qDebug() << "Disconnected!";
    for(int i = 0; i < m_clientSocketLst.count(); ++i)
    {
        QTcpSocket* itemClient = m_clientSocketLst.at(i);
        if( itemClient->socketDescriptor() == -1 )
        {
            m_clientSocketLst.removeAt(i);
            qDebug() << "socket已经关闭";
        }
    }
}
