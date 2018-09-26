#include "customitem.h"
#include "ui_customitem.h"
#include<QtDebug>

CustomItem::CustomItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomItem)
{
    ui->setupUi(this);
}

CustomItem::~CustomItem()
{
    delete ui;
}

QVector<bool> CustomItem::getResult() {
    QVector<bool> vect(3);
    if(ui->checkBox_A->checkState() == Qt::Checked) {
        vect[0] = true;
    }
    if (ui->checkBox_B->checkState() == Qt::Checked) {
        vect[1] = true;
    }
    if (ui->checkBox_C->checkState() == Qt::Checked) {
        vect[2] = true;
    }
    return vect;
}

void CustomItem::setTitle(qint32 seriaNumber, QString title) {
    this->mSeriaNumber = seriaNumber;
    ui->label->setText(title);
}

void CustomItem::setCheckBoxA(QString title) {
    ui->checkBox_A->setText(title);
}

void CustomItem::setCheckBoxB(QString title) {
    ui->checkBox_B->setText(title);
}

void CustomItem::setCheckBoxC(QString title) {
    ui->checkBox_C->setText(title);
}

void CustomItem::on_checkBox_A_stateChanged(int arg1)
{
    qDebug()<< "seriaNumber = " << this->mSeriaNumber <<  ((arg1 == Qt::Checked) ? "选中" : "未选中") << "A";
}

void CustomItem::on_checkBox_B_stateChanged(int arg1)
{
    qDebug()<< "seriaNumber = " << this->mSeriaNumber <<  ((arg1 == Qt::Checked) ? "选中" : "未选中") << "B";
}

void CustomItem::on_checkBox_C_stateChanged(int arg1)
{
    qDebug()<< "seriaNumber = " << this->mSeriaNumber <<  ((arg1 == Qt::Checked) ? "选中" : "未选中") << "C";
}
