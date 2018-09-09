/********************************************************************************
** Form generated from reading UI file 'customitem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMITEM_H
#define UI_CUSTOMITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_A;
    QCheckBox *checkBox_B;
    QCheckBox *checkBox_C;
    QCheckBox *checkBox_D;

    void setupUi(QWidget *CustomItem)
    {
        if (CustomItem->objectName().isEmpty())
            CustomItem->setObjectName(QStringLiteral("CustomItem"));
        CustomItem->resize(1202, 177);
        verticalLayout_2 = new QVBoxLayout(CustomItem);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(CustomItem);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(CustomItem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_A = new QCheckBox(groupBox);
        checkBox_A->setObjectName(QStringLiteral("checkBox_A"));

        verticalLayout->addWidget(checkBox_A);

        checkBox_B = new QCheckBox(groupBox);
        checkBox_B->setObjectName(QStringLiteral("checkBox_B"));

        verticalLayout->addWidget(checkBox_B);

        checkBox_C = new QCheckBox(groupBox);
        checkBox_C->setObjectName(QStringLiteral("checkBox_C"));

        verticalLayout->addWidget(checkBox_C);

        checkBox_D = new QCheckBox(groupBox);
        checkBox_D->setObjectName(QStringLiteral("checkBox_D"));

        verticalLayout->addWidget(checkBox_D);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(CustomItem);

        QMetaObject::connectSlotsByName(CustomItem);
    } // setupUi

    void retranslateUi(QWidget *CustomItem)
    {
        CustomItem->setWindowTitle(QApplication::translate("CustomItem", "Form", nullptr));
        label->setText(QApplication::translate("CustomItem", "1/1217  \351\251\276\351\251\266\346\234\272\345\212\250\350\275\246\345\234\250\351\201\223\350\267\257\344\270\212\350\277\235\345\217\215\351\201\223\350\267\257\344\272\244\351\200\232\345\256\211\345\205\250\346\263\225\347\232\204\350\241\214\344\270\272\357\274\214\345\261\236\344\272\216\344\273\200\344\271\210\350\241\214\344\270\272\357\274\237", nullptr));
        groupBox->setTitle(QString());
        checkBox_A->setText(QApplication::translate("CustomItem", "A\357\274\232\350\277\235\347\253\240\350\241\214\344\270\272", nullptr));
        checkBox_B->setText(QApplication::translate("CustomItem", "B\357\274\232\350\277\235\346\263\225\350\241\214\344\270\272", nullptr));
        checkBox_C->setText(QApplication::translate("CustomItem", "C\357\274\232\350\277\207\345\244\261\350\241\214\344\270\272", nullptr));
        checkBox_D->setText(QApplication::translate("CustomItem", "D\357\274\232\350\277\235\350\247\204\350\241\214\344\270\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomItem: public Ui_CustomItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMITEM_H
