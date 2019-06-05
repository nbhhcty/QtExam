#ifndef EXAMRESUTCELL_H
#define EXAMRESUTCELL_H

#include <QWidget>

namespace Ui {
class ExamResutCell;
}

class ExamResutCell : public QWidget
{
    Q_OBJECT

public:
    explicit ExamResutCell(QWidget *parent = nullptr);
    ~ExamResutCell();
    void setCellWith(QString name, QString id, QString phone, QString score);

private:
    Ui::ExamResutCell *ui;
};

#endif // EXAMRESUTCELL_H
