/********************************************************************************
** Form generated from reading UI file 'examresutcell.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMRESUTCELL_H
#define UI_EXAMRESUTCELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamResutCell
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLabel *phone;
    QLabel *id;
    QLabel *score;

    void setupUi(QWidget *ExamResutCell)
    {
        if (ExamResutCell->objectName().isEmpty())
            ExamResutCell->setObjectName(QStringLiteral("ExamResutCell"));
        ExamResutCell->resize(840, 43);
        horizontalLayout = new QHBoxLayout(ExamResutCell);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        name = new QLabel(ExamResutCell);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

        phone = new QLabel(ExamResutCell);
        phone->setObjectName(QStringLiteral("phone"));

        horizontalLayout->addWidget(phone);

        id = new QLabel(ExamResutCell);
        id->setObjectName(QStringLiteral("id"));

        horizontalLayout->addWidget(id);

        score = new QLabel(ExamResutCell);
        score->setObjectName(QStringLiteral("score"));

        horizontalLayout->addWidget(score);


        retranslateUi(ExamResutCell);

        QMetaObject::connectSlotsByName(ExamResutCell);
    } // setupUi

    void retranslateUi(QWidget *ExamResutCell)
    {
        ExamResutCell->setWindowTitle(QApplication::translate("ExamResutCell", "Form", nullptr));
        name->setText(QApplication::translate("ExamResutCell", "\345\274\240\344\270\211", nullptr));
        phone->setText(QApplication::translate("ExamResutCell", "18310067313", nullptr));
        id->setText(QApplication::translate("ExamResutCell", "372324198809276431", nullptr));
        score->setText(QApplication::translate("ExamResutCell", "89\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamResutCell: public Ui_ExamResutCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMRESUTCELL_H
