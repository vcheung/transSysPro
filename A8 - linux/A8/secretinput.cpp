#include "secretinput.h"
#include "ui_secretinput.h"
#include <QBoxLayout>
#include <QDebug>

secretInput::secretInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secretInput)
{
    ui->setupUi(this);
    this->move(0,0);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(800,480);

    CreateErrorPrompter();

    connect(ui->canBtn,SIGNAL(clicked()),this,SLOT(switchToWorkwidget()));
    connect(ui->sureBtn,SIGNAL(clicked()),this,SLOT(switchToMagWorkwidget()));
}

secretInput::~secretInput()
{
    delete ui;
}

void secretInput::switchToWorkwidget()
{
    emit switchToWorkwidgetSignal();
}

void secretInput::switchToMagWorkwidget()
{
    if(ui->lineEdit->text() == "0000")
    {
        emit switchToMagWorkwidgetSignal();
        ui->lineEdit->clear();
    }
    else
    {
        this->Prompter->setVisible(true);
        ui->lineEdit->clear();
        ui->sureBtn->setDisabled(true);
        ui->canBtn->setDisabled(true);
    }
}

void secretInput::CreateErrorPrompter()
{
    Prompter =  new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout ;
    QLabel *PrompterLab1 = new QLabel("                 提示");
    PrompterLab1->setStyleSheet("font-size:23px");
    QLabel *PrompterLab2 = new QLabel("       密码输入错误，请重新输入!");
    PrompterLab2->setStyleSheet("font-size:23px");
    QPushButton *SureBtn = new QPushButton("确定");
    SureBtn->setStyleSheet("font-size:23px");

    QHBoxLayout *SureBtnLayout = new QHBoxLayout;
    SureBtnLayout->addStretch();
    SureBtnLayout->addWidget(SureBtn);
    SureBtnLayout->addStretch();

    layout->addWidget(PrompterLab1);
    layout->addWidget(PrompterLab2);
    layout->addLayout(SureBtnLayout);

    Prompter->setLayout(layout);
    Prompter->setGeometry(QRect(170,250,450,200));
    Prompter->setStyleSheet("QWidget{background-color: rgb(40, 225, 35)}");

    qDebug("check");
    Prompter->setVisible(false);
    connect(SureBtn,SIGNAL(clicked()),this,SLOT(invisiblePrompterSlot()));
}

void secretInput::invisiblePrompterSlot()
{
    qDebug("check in");
    Prompter->setVisible(false);
    ui->canBtn->setDisabled(false);
    ui->sureBtn->setDisabled(false);
}
