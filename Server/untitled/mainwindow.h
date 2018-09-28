#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include <QTcpServer>
//#include <QTcpSocket>
//#include <QNetworkInterface>
#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow      *ui;
    QTcpServer* server;
    QList<QTcpSocket*> m_clientSocketLst;    //用于保存客户端链表
    void displayError(QAbstractSocket::SocketError socketError);

private slots:
    void on_pushButton_Listen_clicked();
    void on_pushButton_Send_clicked();
    void server_New_Connect();
    void socket_Read_Data();
    void socket_Disconnected();
};

#endif // MAINWINDOW_H

