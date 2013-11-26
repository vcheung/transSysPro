#include "workwidget.h"
#include "ui_workwidget.h"
#include <QDateTime>
#include <QTimer>
#include "widget.h"
#include "secretinput.h"
#include <QDebug>

workwidget::workwidget(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workwidget)
{
    ui->setupUi(this);
    m_type = type;
    switch(m_type)
    {
    case 0: ui->guanliBtn->setDisabled(true);break;
    case 1: ui->guanliBtn->setDisabled(false);break;
    }

    QTimer *WorkTimer = new QTimer;
    WorkTimer->start(1000);
    connect(WorkTimer,SIGNAL(timeout()),this,SLOT(updatetime()));

    connect(this,SIGNAL(updateShowSignal()),this,SLOT(updateShowSlot()));
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

void workwidget::showInf(carDis *pW_mcarDis)
{
    if(pW_mcarDis == NULL)
        return;
    memset(&W_mcarDis,0,sizeof(carDis));
    memcpy(&W_mcarDis,pW_mcarDis,sizeof(carDis));
    emit updateShowSignal();
}

void workwidget::updateShowSlot()
{
    ui->name->setText(tr(W_mcarDis.name));
    ui->ID->setText(tr(W_mcarDis.ID));
    ui->carID->setText(tr(W_mcarDis.carID));
    ui->stWeight->setNum((int)W_mcarDis.stWeight);
    ui->ADWeight->setNum((int)W_mcarDis.ADWeight);
//    qDebug()<<"show car";
}
