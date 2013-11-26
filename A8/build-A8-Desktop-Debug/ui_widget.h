/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Nov 26 15:54:46 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *Timelab;
    QLabel *label;
    QPushButton *manaBtn;
    QPushButton *visiBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        QFont font;
        font.setItalic(true);
        Widget->setFont(font);
        Widget->setAutoFillBackground(true);
        Timelab = new QLabel(Widget);
        Timelab->setObjectName(QString::fromUtf8("Timelab"));
        Timelab->setGeometry(QRect(540, 10, 250, 30));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        Timelab->setFont(font1);
        Timelab->setAutoFillBackground(false);
        Timelab->setFrameShadow(QFrame::Plain);
        Timelab->setLineWidth(5);
        Timelab->setAlignment(Qt::AlignCenter);
        Timelab->setWordWrap(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 180, 400, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        manaBtn = new QPushButton(Widget);
        manaBtn->setObjectName(QString::fromUtf8("manaBtn"));
        manaBtn->setGeometry(QRect(220, 300, 130, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        font3.setItalic(false);
        manaBtn->setFont(font3);
        visiBtn = new QPushButton(Widget);
        visiBtn->setObjectName(QString::fromUtf8("visiBtn"));
        visiBtn->setGeometry(QRect(450, 300, 130, 40));
        visiBtn->setFont(font3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        Timelab->setText(QApplication::translate("Widget", "time", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\350\275\246\350\276\206\344\277\241\346\201\257\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        manaBtn->setText(QApplication::translate("Widget", "\347\256\241\347\220\206\344\272\272\345\221\230\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        visiBtn->setText(QApplication::translate("Widget", "\346\270\270\345\256\242\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
