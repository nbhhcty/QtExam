#include "checkingquestionitem.h"
#include "ui_checkingquestionitem.h"
#include<QtDebug>

CheckingQuestionItem::CheckingQuestionItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckingQuestionItem)
{
    ui->setupUi(this);
}

CheckingQuestionItem::~CheckingQuestionItem()
{
    delete ui;
}

void CheckingQuestionItem::setTitle(qint32 seriaNumber, QString title)
{
    this->mSeriaNumber = seriaNumber;
    ui->label->setText(title);
}

qint32 CheckingQuestionItem::getResult() {
     qint32 result = -1;
     if(ui->checkBox->checkState() == Qt::Checked) {
        result = 1;
     }
     else if (ui->checkBox_2->checkState() == Qt::Checked) {
         result = 0;
     }
     return result;
}

void CheckingQuestionItem::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {
        qDebug()<< "seriaNumber = " << this->mSeriaNumber  << "选择:正确";
        ui->checkBox_2->setCheckState(Qt::Unchecked);
    }
}

void CheckingQuestionItem::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {
        qDebug()<< "seriaNumber = " << this->mSeriaNumber  << "选择:错误";
        ui->checkBox->setCheckState(Qt::Unchecked);
    }
}
