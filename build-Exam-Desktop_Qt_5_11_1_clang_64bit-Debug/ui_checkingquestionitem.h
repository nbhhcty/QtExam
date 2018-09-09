/********************************************************************************
** Form generated from reading UI file 'checkingquestionitem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINGQUESTIONITEM_H
#define UI_CHECKINGQUESTIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckingQuestionItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CheckingQuestionItem)
    {
        if (CheckingQuestionItem->objectName().isEmpty())
            CheckingQuestionItem->setObjectName(QStringLiteral("CheckingQuestionItem"));
        CheckingQuestionItem->resize(931, 112);
        verticalLayout_2 = new QVBoxLayout(CheckingQuestionItem);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(CheckingQuestionItem);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(CheckingQuestionItem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(772, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(CheckingQuestionItem);

        QMetaObject::connectSlotsByName(CheckingQuestionItem);
    } // setupUi

    void retranslateUi(QWidget *CheckingQuestionItem)
    {
        CheckingQuestionItem->setWindowTitle(QApplication::translate("CheckingQuestionItem", "Form", nullptr));
        label->setText(QApplication::translate("CheckingQuestionItem", "\345\210\244\346\226\255\351\242\230", nullptr));
        groupBox->setTitle(QString());
        checkBox->setText(QApplication::translate("CheckingQuestionItem", "\346\255\243\347\241\256", nullptr));
        checkBox_2->setText(QApplication::translate("CheckingQuestionItem", "\351\224\231\350\257\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckingQuestionItem: public Ui_CheckingQuestionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINGQUESTIONITEM_H
