#ifndef CHECKINGQUESTIONITEM_H
#define CHECKINGQUESTIONITEM_H

#include <QWidget>

namespace Ui {
class CheckingQuestionItem;
}

class CheckingQuestionItem : public QWidget
{
    Q_OBJECT

public:
    explicit CheckingQuestionItem(QWidget *parent = nullptr);
    ~CheckingQuestionItem();

private:
    Ui::CheckingQuestionItem *ui;
    qint32 mSeriaNumber;

public:
    // 设置题目:设置编号，用来识别完成了哪一道题
    void setTitle(qint32 seriaNumber, QString title);
    // 获取当前编号的结果
    qint32 getResult();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_checkBox_2_stateChanged(int arg1);
};

#endif // CHECKINGQUESTIONITEM_H
