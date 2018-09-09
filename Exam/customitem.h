#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QWidget>

namespace Ui {
class CustomItem;
}

class CustomItem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomItem(QWidget *parent = nullptr);
    ~CustomItem();

private:
    Ui::CustomItem *ui;
    qint32 mSeriaNumber;

public :
    // 设置编号，用来识别完成了哪一道题
    void setTitle(qint32 seriaNumber, QString title);
    void setCheckBoxA(QString title);
    void setCheckBoxB(QString title);
    void setCheckBoxC(QString title);
    void setCheckBoxD(QString title);
    // 获取当前编号的结果
    QVector<bool> getResult();

private slots:
    void on_checkBox_A_stateChanged(int arg1);
    void on_checkBox_B_stateChanged(int arg1);
    void on_checkBox_C_stateChanged(int arg1);
    void on_checkBox_D_stateChanged(int arg1);
};

#endif // CUSTOMITEM_H
