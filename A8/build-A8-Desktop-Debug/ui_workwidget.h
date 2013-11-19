/********************************************************************************
** Form generated from reading UI file 'workwidget.ui'
**
** Created: Tue Nov 19 16:14:42 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKWIDGET_H
#define UI_WORKWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workwidget
{
public:
    QLabel *Timelab;
    QPushButton *mainBtn;
    QPushButton *weiguiBtn;
    QPushButton *guanliBtn;
    QPushButton *jinchuBtn;
    QPushButton *returnWork;
    QLabel *label;

    void setupUi(QWidget *workwidget)
    {
        if (workwidget->objectName().isEmpty())
            workwidget->setObjectName(QString::fromUtf8("workwidget"));
        workwidget->resize(800, 480);
        Timelab = new QLabel(workwidget);
        Timelab->setObjectName(QString::fromUtf8("Timelab"));
        Timelab->setGeometry(QRect(540, 10, 250, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        Timelab->setFont(font);
        Timelab->setAutoFillBackground(false);
        Timelab->setFrameShadow(QFrame::Plain);
        Timelab->setLineWidth(5);
        Timelab->setAlignment(Qt::AlignCenter);
        Timelab->setWordWrap(false);
        mainBtn = new QPushButton(workwidget);
        mainBtn->setObjectName(QString::fromUtf8("mainBtn"));
        mainBtn->setGeometry(QRect(0, 90, 130, 30));
        weiguiBtn = new QPushButton(workwidget);
        weiguiBtn->setObjectName(QString::fromUtf8("weiguiBtn"));
        weiguiBtn->setGeometry(QRect(0, 130, 130, 30));
        guanliBtn = new QPushButton(workwidget);
        guanliBtn->setObjectName(QString::fromUtf8("guanliBtn"));
        guanliBtn->setGeometry(QRect(0, 210, 130, 30));
        jinchuBtn = new QPushButton(workwidget);
        jinchuBtn->setObjectName(QString::fromUtf8("jinchuBtn"));
        jinchuBtn->setGeometry(QRect(0, 170, 130, 30));
        returnWork = new QPushButton(workwidget);
        returnWork->setObjectName(QString::fromUtf8("returnWork"));
        returnWork->setGeometry(QRect(0, 290, 130, 30));
        label = new QLabel(workwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 400, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(workwidget);

        QMetaObject::connectSlotsByName(workwidget);
    } // setupUi

    void retranslateUi(QWidget *workwidget)
    {
        workwidget->setWindowTitle(QApplication::translate("workwidget", "Form", 0, QApplication::UnicodeUTF8));
        Timelab->setText(QApplication::translate("workwidget", "time", 0, QApplication::UnicodeUTF8));
        mainBtn->setText(QApplication::translate("workwidget", "\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        weiguiBtn->setText(QApplication::translate("workwidget", "\350\277\235\350\247\204\350\275\246\350\276\206\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        guanliBtn->setText(QApplication::translate("workwidget", "\350\275\246\350\276\206\344\277\241\346\201\257\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        jinchuBtn->setText(QApplication::translate("workwidget", "\350\275\246\350\276\206\350\277\233\345\207\272\346\203\205\345\206\265", 0, QApplication::UnicodeUTF8));
        returnWork->setText(QApplication::translate("workwidget", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("workwidget", "\350\275\246\350\276\206\344\277\241\346\201\257\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class workwidget: public Ui_workwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKWIDGET_H
