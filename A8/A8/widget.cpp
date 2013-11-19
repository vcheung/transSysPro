#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mageSecretInput = new secretInput;
    workW = new workwidget(0);
    magWorkW = new workwidget(1);

    QTimer *WorkTimer = new QTimer;
    WorkTimer->start(1000);
    connect(WorkTimer,SIGNAL(timeout()),this,SLOT(updatetime()));
    connect(this,SIGNAL(switchToWorkWSignal()),this,SLOT(workWShow()));
    connect(this,SIGNAL(switchToSecretSignal()),this,SLOT(toSecret()));
    connect(mageSecretInput,SIGNAL(switchToWorkwidgetSignal()),this,SLOT(manShow()));
    connect(mageSecretInput,SIGNAL(switchToMagWorkwidgetSignal()),this,SLOT(magWorkWShow()));
    connect(workW,SIGNAL(switchToManSignal()),this,SLOT(manShow()));
    connect(magWorkW,SIGNAL(switchToManSignal()),this,SLOT(manShow()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatetime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString timestr =time.toString(" yyyyÄêMMÔÂddÈÕ  hh:mm:ss  ");
    ui->Timelab->setText(timestr);
}

void Widget::workWShow()
{
    workW->show();
    this->hide();
}

void Widget::magWorkWShow()
{
    mageSecretInput->hide();
    magWorkW->show();
    this->hide();
}

void Widget::manShow()
{
    mageSecretInput->hide();
    workW->hide();
    magWorkW->hide();
    this->show();
}

void Widget::toSecret()
{
    mageSecretInput->show();
    this->hide();
}

void Widget::on_visiBtn_clicked()
{
    emit switchToWorkWSignal();
}

void Widget::on_manaBtn_clicked()
{
    emit switchToSecretSignal();
}
