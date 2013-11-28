#include "workwidget.h"
#include "ui_workwidget.h"
#include <QDateTime>
#include <QTimer>
#include "widget.h"
#include "secretinput.h"
#include <QDebug>
#include <QApplication>

#include <QtXml/qdom.h>
#include <QFile>
#include <QTextStream>

//#include <QtXml/qdom.h>
//#include <QFile>
//#include <QTextStream>
Ui::Widget *pUipoint;

workwidget::workwidget(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workwidget)
{
    ui->setupUi(this);
    this->move(0,0);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(800,480);

    m_type = type;
    switch(m_type)
    {
    case 0: ui->guanliBtn->setDisabled(true);break;
    case 1: ui->guanliBtn->setDisabled(false);break;
    }

    mxmlfile = new xmlfile("carData.xml");

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
    QString timestr =time.toString(" yyyy年MM月dd日  hh:mm:ss  ");
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

//    if(mxmlfile->sameOrNot(W_mcarDis) == false)
//    {
//        mxmlfile->writeFile(W_mcarDis);
//        showList();
//    }
    mxmlfile->writeFile(W_mcarDis);
    showList();
}

void workwidget::showList()
{
//    ui->listWidget->clear();
    QFile file("carData.xml");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {
        if(n.isElement())
        {
            QDomElement e = n.toElement();
            ui->listWidget->addItem(e.tagName()+"_车牌号码:"+e.attribute(tr("车牌号码")));
            QDomNodeList list = e.childNodes();
            for(int i=0;i<list.count();i++)
            {
                QDomNode node = list.at(i);
                if(node.isElement())
                    ui->listWidget->addItem(" "+node.toElement().tagName()
                                            +":"+node.toElement().text());
            }
        }
        n=n.nextSibling();
    }
}

void workwidget::on_quit_clicked()
{
    qApp->exit();
}
