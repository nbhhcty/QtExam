#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "checkingquestionitem.h"
#include "customitem.h"

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

private:
    Ui::MainWindow *ui;
    QVector<CustomItem*> vect_choiceItem;
    QVector<CheckingQuestionItem*> vect_checkItem;
};

#endif // MAINWINDOW_H
