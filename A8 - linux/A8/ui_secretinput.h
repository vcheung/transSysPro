/********************************************************************************
** Form generated from reading UI file 'secretinput.ui'
**
** Created: Thu Nov 28 09:56:27 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECRETINPUT_H
#define UI_SECRETINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secretInput
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *sureBtn;
    QPushButton *canBtn;

    void setupUi(QWidget *secretInput)
    {
        if (secretInput->objectName().isEmpty())
            secretInput->setObjectName(QString::fromUtf8("secretInput"));
        secretInput->resize(800, 480);
        label = new QLabel(secretInput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 120, 400, 50));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(secretInput);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 220, 200, 50));
        sureBtn = new QPushButton(secretInput);
        sureBtn->setObjectName(QString::fromUtf8("sureBtn"));
        sureBtn->setGeometry(QRect(220, 340, 130, 30));
        canBtn = new QPushButton(secretInput);
        canBtn->setObjectName(QString::fromUtf8("canBtn"));
        canBtn->setGeometry(QRect(450, 340, 130, 30));

        retranslateUi(secretInput);

        QMetaObject::connectSlotsByName(secretInput);
    } // setupUi

    void retranslateUi(QWidget *secretInput)
    {
        secretInput->setWindowTitle(QApplication::translate("secretInput", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("secretInput", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        sureBtn->setText(QApplication::translate("secretInput", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        canBtn->setText(QApplication::translate("secretInput", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class secretInput: public Ui_secretInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECRETINPUT_H
