/********************************************************************************
** Form generated from reading UI file 'myinputpanelform.ui'
**
** Created: Wed Nov 27 13:11:03 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINPUTPANELFORM_H
#define UI_MYINPUTPANELFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInputPanelForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *panelButton_1;
    QPushButton *panelButton_2;
    QPushButton *panelButton_3;
    QPushButton *panelButton_4;
    QPushButton *panelButton_5;
    QPushButton *panelButton_6;
    QPushButton *closeButton_2;
    QPushButton *panelButton_7;
    QPushButton *panelButton_8;
    QPushButton *panelButton_9;
    QPushButton *panelButton_0;
    QPushButton *panelButton_star;
    QPushButton *panelButton_hash;
    QPushButton *closeButton;

    void setupUi(QWidget *MyInputPanelForm)
    {
        if (MyInputPanelForm->objectName().isEmpty())
            MyInputPanelForm->setObjectName(QString::fromUtf8("MyInputPanelForm"));
        MyInputPanelForm->setWindowModality(Qt::NonModal);
        MyInputPanelForm->resize(578, 104);
        MyInputPanelForm->setStyleSheet(QString::fromUtf8("border-color: rgb(85, 170, 127);\n"
"font: 15pt \"\346\245\267\344\275\223\";"));
        MyInputPanelForm->setInputMethodHints(Qt::ImhNone);
        gridLayout = new QGridLayout(MyInputPanelForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        panelButton_1 = new QPushButton(MyInputPanelForm);
        panelButton_1->setObjectName(QString::fromUtf8("panelButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(panelButton_1->sizePolicy().hasHeightForWidth());
        panelButton_1->setSizePolicy(sizePolicy);
        panelButton_1->setMinimumSize(QSize(45, 40));
        panelButton_1->setFocusPolicy(Qt::NoFocus);
        panelButton_1->setProperty("buttonValue", QVariant(QChar(49)));

        gridLayout->addWidget(panelButton_1, 0, 0, 1, 1);

        panelButton_2 = new QPushButton(MyInputPanelForm);
        panelButton_2->setObjectName(QString::fromUtf8("panelButton_2"));
        sizePolicy.setHeightForWidth(panelButton_2->sizePolicy().hasHeightForWidth());
        panelButton_2->setSizePolicy(sizePolicy);
        panelButton_2->setMinimumSize(QSize(45, 40));
        panelButton_2->setFocusPolicy(Qt::NoFocus);
        panelButton_2->setProperty("buttonValue", QVariant(QChar(50)));

        gridLayout->addWidget(panelButton_2, 0, 1, 1, 1);

        panelButton_3 = new QPushButton(MyInputPanelForm);
        panelButton_3->setObjectName(QString::fromUtf8("panelButton_3"));
        sizePolicy.setHeightForWidth(panelButton_3->sizePolicy().hasHeightForWidth());
        panelButton_3->setSizePolicy(sizePolicy);
        panelButton_3->setMinimumSize(QSize(45, 40));
        panelButton_3->setFocusPolicy(Qt::NoFocus);
        panelButton_3->setProperty("buttonValue", QVariant(QChar(51)));

        gridLayout->addWidget(panelButton_3, 0, 2, 1, 1);

        panelButton_4 = new QPushButton(MyInputPanelForm);
        panelButton_4->setObjectName(QString::fromUtf8("panelButton_4"));
        sizePolicy.setHeightForWidth(panelButton_4->sizePolicy().hasHeightForWidth());
        panelButton_4->setSizePolicy(sizePolicy);
        panelButton_4->setMinimumSize(QSize(45, 40));
        panelButton_4->setFocusPolicy(Qt::NoFocus);
        panelButton_4->setProperty("buttonValue", QVariant(QChar(52)));

        gridLayout->addWidget(panelButton_4, 0, 3, 1, 1);

        panelButton_5 = new QPushButton(MyInputPanelForm);
        panelButton_5->setObjectName(QString::fromUtf8("panelButton_5"));
        sizePolicy.setHeightForWidth(panelButton_5->sizePolicy().hasHeightForWidth());
        panelButton_5->setSizePolicy(sizePolicy);
        panelButton_5->setMinimumSize(QSize(45, 40));
        panelButton_5->setFocusPolicy(Qt::NoFocus);
        panelButton_5->setProperty("buttonValue", QVariant(QChar(53)));

        gridLayout->addWidget(panelButton_5, 0, 4, 1, 1);

        panelButton_6 = new QPushButton(MyInputPanelForm);
        panelButton_6->setObjectName(QString::fromUtf8("panelButton_6"));
        sizePolicy.setHeightForWidth(panelButton_6->sizePolicy().hasHeightForWidth());
        panelButton_6->setSizePolicy(sizePolicy);
        panelButton_6->setMinimumSize(QSize(45, 40));
        panelButton_6->setFocusPolicy(Qt::NoFocus);
        panelButton_6->setProperty("buttonValue", QVariant(QChar(54)));

        gridLayout->addWidget(panelButton_6, 0, 5, 1, 1);

        closeButton_2 = new QPushButton(MyInputPanelForm);
        closeButton_2->setObjectName(QString::fromUtf8("closeButton_2"));
        closeButton_2->setMinimumSize(QSize(75, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        closeButton_2->setFont(font);
        closeButton_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(closeButton_2, 0, 6, 1, 1);

        panelButton_7 = new QPushButton(MyInputPanelForm);
        panelButton_7->setObjectName(QString::fromUtf8("panelButton_7"));
        sizePolicy.setHeightForWidth(panelButton_7->sizePolicy().hasHeightForWidth());
        panelButton_7->setSizePolicy(sizePolicy);
        panelButton_7->setMinimumSize(QSize(45, 40));
        panelButton_7->setFocusPolicy(Qt::NoFocus);
        panelButton_7->setProperty("buttonValue", QVariant(QChar(55)));

        gridLayout->addWidget(panelButton_7, 1, 0, 1, 1);

        panelButton_8 = new QPushButton(MyInputPanelForm);
        panelButton_8->setObjectName(QString::fromUtf8("panelButton_8"));
        sizePolicy.setHeightForWidth(panelButton_8->sizePolicy().hasHeightForWidth());
        panelButton_8->setSizePolicy(sizePolicy);
        panelButton_8->setMinimumSize(QSize(45, 40));
        panelButton_8->setFocusPolicy(Qt::NoFocus);
        panelButton_8->setProperty("buttonValue", QVariant(QChar(56)));

        gridLayout->addWidget(panelButton_8, 1, 1, 1, 1);

        panelButton_9 = new QPushButton(MyInputPanelForm);
        panelButton_9->setObjectName(QString::fromUtf8("panelButton_9"));
        sizePolicy.setHeightForWidth(panelButton_9->sizePolicy().hasHeightForWidth());
        panelButton_9->setSizePolicy(sizePolicy);
        panelButton_9->setMinimumSize(QSize(45, 40));
        panelButton_9->setFocusPolicy(Qt::NoFocus);
        panelButton_9->setProperty("buttonValue", QVariant(QChar(57)));

        gridLayout->addWidget(panelButton_9, 1, 2, 1, 1);

        panelButton_0 = new QPushButton(MyInputPanelForm);
        panelButton_0->setObjectName(QString::fromUtf8("panelButton_0"));
        sizePolicy.setHeightForWidth(panelButton_0->sizePolicy().hasHeightForWidth());
        panelButton_0->setSizePolicy(sizePolicy);
        panelButton_0->setMinimumSize(QSize(45, 40));
        panelButton_0->setFocusPolicy(Qt::NoFocus);
        panelButton_0->setProperty("buttonValue", QVariant(QChar(48)));

        gridLayout->addWidget(panelButton_0, 1, 3, 1, 1);

        panelButton_star = new QPushButton(MyInputPanelForm);
        panelButton_star->setObjectName(QString::fromUtf8("panelButton_star"));
        sizePolicy.setHeightForWidth(panelButton_star->sizePolicy().hasHeightForWidth());
        panelButton_star->setSizePolicy(sizePolicy);
        panelButton_star->setMinimumSize(QSize(45, 40));
        panelButton_star->setFocusPolicy(Qt::NoFocus);
        panelButton_star->setProperty("buttonValue", QVariant(QChar(45)));

        gridLayout->addWidget(panelButton_star, 1, 4, 1, 1);

        panelButton_hash = new QPushButton(MyInputPanelForm);
        panelButton_hash->setObjectName(QString::fromUtf8("panelButton_hash"));
        sizePolicy.setHeightForWidth(panelButton_hash->sizePolicy().hasHeightForWidth());
        panelButton_hash->setSizePolicy(sizePolicy);
        panelButton_hash->setMinimumSize(QSize(45, 40));
        panelButton_hash->setFocusPolicy(Qt::NoFocus);
        panelButton_hash->setProperty("buttonValue", QVariant(QChar(46)));

        gridLayout->addWidget(panelButton_hash, 1, 5, 1, 1);

        closeButton = new QPushButton(MyInputPanelForm);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(75, 40));
        closeButton->setFont(font);
        closeButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(closeButton, 1, 6, 1, 1);


        retranslateUi(MyInputPanelForm);

        QMetaObject::connectSlotsByName(MyInputPanelForm);
    } // setupUi

    void retranslateUi(QWidget *MyInputPanelForm)
    {
        MyInputPanelForm->setWindowTitle(QApplication::translate("MyInputPanelForm", "Input Panel", 0, QApplication::UnicodeUTF8));
        panelButton_1->setText(QApplication::translate("MyInputPanelForm", "1", 0, QApplication::UnicodeUTF8));
        panelButton_2->setText(QApplication::translate("MyInputPanelForm", "2", 0, QApplication::UnicodeUTF8));
        panelButton_3->setText(QApplication::translate("MyInputPanelForm", "3", 0, QApplication::UnicodeUTF8));
        panelButton_4->setText(QApplication::translate("MyInputPanelForm", "4", 0, QApplication::UnicodeUTF8));
        panelButton_5->setText(QApplication::translate("MyInputPanelForm", "5", 0, QApplication::UnicodeUTF8));
        panelButton_6->setText(QApplication::translate("MyInputPanelForm", "6", 0, QApplication::UnicodeUTF8));
        closeButton_2->setText(QApplication::translate("MyInputPanelForm", "BackSpace", 0, QApplication::UnicodeUTF8));
        panelButton_7->setText(QApplication::translate("MyInputPanelForm", "7", 0, QApplication::UnicodeUTF8));
        panelButton_8->setText(QApplication::translate("MyInputPanelForm", "8", 0, QApplication::UnicodeUTF8));
        panelButton_9->setText(QApplication::translate("MyInputPanelForm", "9", 0, QApplication::UnicodeUTF8));
        panelButton_0->setText(QApplication::translate("MyInputPanelForm", "0", 0, QApplication::UnicodeUTF8));
        panelButton_star->setText(QApplication::translate("MyInputPanelForm", "-", 0, QApplication::UnicodeUTF8));
        panelButton_hash->setText(QApplication::translate("MyInputPanelForm", ".", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("MyInputPanelForm", "Enter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyInputPanelForm: public Ui_MyInputPanelForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINPUTPANELFORM_H
