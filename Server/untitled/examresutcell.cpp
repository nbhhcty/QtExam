#include "examresutcell.h"
#include "ui_examresutcell.h"

ExamResutCell::ExamResutCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExamResutCell)
{
    ui->setupUi(this);
}

ExamResutCell::~ExamResutCell()
{
    delete ui;
}

void ExamResutCell::setCellWith(QString name, QString id, QString phone, QString score)
{
    ui->name->setText(name);
    ui->id->setText(id);
    ui->phone->setText(phone);
    ui->score->setText(score);
}
