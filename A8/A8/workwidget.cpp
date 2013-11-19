#include "workwidget.h"
#include "ui_workwidget.h"
#include <QDateTime>
#include <QTimer>
#include "widget.h"
#include "secretinput.h"

workwidget::workwidget(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workwidget)
{
    ui->setupUi(this);

    QTimer *WorkTimer = new QTimer;
    WorkTimer->start(1000);
    connect(WorkTimer,SIGNAL(timeout()),this,SLOT(updatetime()));

    m_type = type;
    switch(m_type)
    {
    case 0: ui->guanliBtn->setDisabled(true);break;
    case 1: ui->guanliBtn->setDisabled(false);break;
    }
}

workwidget::~workwidget()
{
    delete ui;
}

void workwidget::updatetime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString timestr =time.toString(" yyyyÄêMMÔÂddÈÕ  hh:mm:ss  ");
    ui->Timelab->setText(timestr);
}

void workwidget::on_returnWork_clicked()
{
    emit switchToManSignal();
}
