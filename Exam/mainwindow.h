#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "checkingquestionitem.h"
#include "customitem.h"

#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void socket_Read_Data();
    void socket_Disconnected();

private:
    Ui::MainWindow *ui;
    QVector<CustomItem*> vect_choiceItem;
    QVector<CheckingQuestionItem*> vect_checkItem;
    QTcpSocket *socket;

    void initSocket();
    void startConnect();
};

#endif // MAINWINDOW_H
