#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QAxObject>
//#include <QListWidgetItem>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonDocument>

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

        QString out;
        QJsonObject object;
        QJsonArray result_array;
        QJsonParseError jsonError;
        //将对应文件转化为json文档
        QJsonDocument Docu(QJsonDocument::fromJson(val.toUtf8(),&jsonError));
        if(jsonError.error != QJsonParseError::NoError)
        {
             qDebug()<<"json error...";
             return ;
        }
        if( Docu.isObject()) //JSON文档为对象
        {
            object =  Docu.object();    //转化为对象
            QString keyChoiceQuestion = "选择题";
            if(object.contains(keyChoiceQuestion))
            {
                QJsonValue value = object.value(keyChoiceQuestion);
                QJsonArray choiceQuestion;
                if(value.isArray())
                    choiceQuestion = value.toArray();

                for(int i = 0; i < choiceQuestion.count(); i++) {
                    QJsonValue value = choiceQuestion.at(i);
                    QListWidgetItem *nitem = new QListWidgetItem(ui->listWidget_choice);
                    nitem->setSizeHint(QSize(0,153));
                    ui->listWidget_choice->addItem(nitem);
                    CustomItem* custItem = new CustomItem();
                    custItem->setTitle(value["编号"].toString().toInt(), value["编号"].toString() + "、" + value["题目"].toString());
                    custItem->setCheckBoxA("A：" + value["选项A"].toString());
                    custItem->setCheckBoxB("B：" + value["选项B"].toString());
                    custItem->setCheckBoxC("C：" + value["选项C"].toString());
                    custItem->setWhatsThis(value["答案"].toString());
                    ui->listWidget_choice->setItemWidget(nitem, custItem);
                    this->vect_choiceItem.append(custItem);
                }
            }
         }

        QListWidgetItem *nitem = new QListWidgetItem(ui->listWidget);
        nitem->setSizeHint(QSize(0,43));
        ui->listWidget->addItem(nitem);
        ExamResutCell* cell = new ExamResutCell();
        cell->setCellWith("", "", "", "");
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

//void onExportExcel(QString filePath)
//{
//    QAxObject *work_book = NULL;
//    QAxObject excel("Excel.Application");
//    excel.setProperty("Visible", false);
//    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
//    QAxObject *work_books = excel.querySubObject("WorkBooks");
//    QFile xlsFile(filePath);
//    if (xlsFile.exists()) {
//        work_book = work_books->querySubObject("Open(const QString &)", filePath);
//    }
//    else {
//        work_books->dynamicCall("Add");
//        work_book = excel.querySubObject("ActiveWorkBook");
//    }
//    QAxObject *work_sheets = work_book->querySubObject("Sheets");
//    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);

//    QAxObject *cell = first_sheet->querySubObject("Cells(int,int)", 1, 1);
//    cell->setProperty("Value", "单元格内容");

////    cell->setProperty("RowHeight", 50);  //设置单元格行高
////    cell->setProperty("ColumnWidth", 30);  //设置单元格列宽
////    cell->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152
////    cell->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107
////    cell->setProperty("WrapText", true);  //内容过多，自动换行
////    //cell->dynamicCall("ClearContents()");  //清空单元格内容

////    QAxObject* interior = cell->querySubObject("Interior");
////    interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）

////    QAxObject* border = cell->querySubObject("Borders");
////    border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）

////    QAxObject *font = cell->querySubObject("Font");  //获取单元格字体
////    font->setProperty("Name", QStringLiteral("华文彩云"));  //设置单元格字体
////    font->setProperty("Bold", true);  //设置单元格字体加粗
////    font->setProperty("Size", 20);  //设置单元格字体大小
////    font->setProperty("Italic", true);  //设置单元格字体斜体
////    font->setProperty("Underline", 2);  //设置单元格下划线
////    font->setProperty("Color", QColor(255, 0, 0));  //设置单元格字体颜色（红色）



//    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(filePath)); //转换路径不可少，否则会崩溃
//    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
//    excel.dynamicCall("Quit(void)");  //退出
//}
