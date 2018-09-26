#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFile>
#include<QDebug>
#include<QJsonObject>
#include<QJsonParseError>
#include<QJsonArray>
#include<QJsonDocument>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->pushButton, SIGNAL( clicked(bool)), this, SLOT(OnShowClicked(bool)));

    QFile file("/Users/wsk/Desktop/农机考试.json");
    if(!file.open(QFile::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"json opened fail";
        return;
    }
    //
    QString  val= file.readAll();
    file.close();

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
                ui->listWidget_choice->setItemWidget(nitem, custItem);
                this->vect_choiceItem.append(custItem);
            }
        }

        QString keyCheckingQuestion = "判断题";
        if(object.contains(keyCheckingQuestion))
        {
            QJsonValue value = object.value(keyCheckingQuestion);
            QJsonArray checkingQuestion;
            if(value.isArray())
                checkingQuestion = value.toArray();

            for(int i = 0; i < checkingQuestion.count(); i++) {
                QJsonValue value = checkingQuestion.at(i);
                QListWidgetItem *nitem = new QListWidgetItem(ui->listWidget_check);
                nitem->setSizeHint(QSize(0,112));
                ui->listWidget_check->addItem(nitem);
                CheckingQuestionItem* checkItem = new CheckingQuestionItem();
                checkItem->setTitle(value["编号"].toString().toInt(), value["编号"].toString() + "、" + value["题目"].toString());
                ui->listWidget_check->setItemWidget(nitem, checkItem);
                this->vect_checkItem.append(checkItem);
            }
        }
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 点击交卷按钮
void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit_name->text().length() <= 0) {
        QMessageBox msg;
        msg.setWindowTitle(tr("提示"));
        msg.setText("请填写正确的姓名");
        msg.setStyleSheet("font: 14pt;background-color:rgb(220, 0, 0)");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("确定"),QMessageBox::ActionRole);
        msg.exec();
        return;
    }
    if (ui->lineEdit_id->text().length() <= 0) {
        QMessageBox msg;
        msg.setWindowTitle(tr("提示"));
        msg.setText("请填写正确的身份证号码");
        msg.setStyleSheet("font: 14pt;background-color:rgb(220, 0, 0)");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("确定"),QMessageBox::ActionRole);
        msg.exec();
        return;
    }
    if (ui->lineEdit_phone->text().length() != 11) {
        QMessageBox msg;
        msg.setWindowTitle(tr("提示"));
        msg.setText("请填写正确的手机号码");
        msg.setStyleSheet("font: 14pt;background-color:rgb(220, 0, 0)");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("确定"),QMessageBox::ActionRole);
        msg.exec();
        return;
    }
    qDebug() << "获取选择题的结果";
    QVector<CustomItem*>::iterator iterChoice;
    for (iterChoice=this->vect_choiceItem.begin(); iterChoice!=this->vect_choiceItem.end(); iterChoice++)
    {
        qDebug() << ((CustomItem*)(*iterChoice))->getResult();
    }

    qDebug() << "获取判断题的结果";
    QVector<CheckingQuestionItem*>::iterator iterCheck;
    for (iterCheck=this->vect_checkItem.begin(); iterCheck!=this->vect_checkItem.end(); iterCheck++)
    {
        qDebug() << ((CheckingQuestionItem*)(*iterCheck))->getResult();
    }

    // 设置交卷按钮不可用
    ui->pushButton->setEnabled(0);
}
