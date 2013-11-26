#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>
#include <QTimer>
#include <QDebug>

Widget *pMainWnd = NULL;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mageSecretInput = new secretInput;
    workW = new workwidget(0);
    magWorkW = new workwidget(1);

    serialManage();

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
    QString timestr =time.toString(" yyyy年MM月dd日  hh:mm:ss  ");
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

/* 串口 */
void Widget::serialManage()
{
    if(pSer_Com == NULL)
    {
        pSer_Com = new serial;
        if(pSer_Com == NULL)
            return;
        if(!pSer_Com->Initcom(ComDataArriveOK,"COM2",
                              BAUD115200,DATA_8,PAR_NONE,STOP_1,100))
            qDebug()<<"COM open fail!";
        else
        {
            qDebug()<<"serial suceess";
            QTimer *TimerSerData = new QTimer;
            connect(TimerSerData,SIGNAL(timeout()),this,SLOT(SendModDataSlot()));
            TimerSerData->start(200);
        }
    }
}

void Widget::SendModDataSlot()
{
    static uint i=0;
    i++;
    SendModData(SendControlData,SendIsSaveState,i);
    if(i>255)
        i=0;
}

void Widget::ComDataArriveOK(char *DataBuff,ulong m_ulen)
{
    if(pMainWnd->DataCrcCheck(DataBuff,m_ulen)&&pMainWnd!=NULL)
    {
        Comdata mData;
        memset(&mData,0,sizeof(Comdata));
        memcpy(mData.DataBuff,DataBuff,m_ulen);
        mData.Len=m_ulen;
        PutDataIntoQueuen(&mData);
    }
}

ulong Widget::CRCCheck(char *crcBuff, ulong size)
{
    ulong m_uCrcValue=0;
    if(NULL==crcBuff || size<0)
        return m_uCrcValue;
    //首先为crc开辟两个字节的内存空间
    unsigned short crc = 0xffff;
    unsigned short a,j,k;
    unsigned char crcValue=0;
    for(a=0;a<size;a++)
    {
        //crc和第a个字节里的值异或，新值赋给crc。注意gemfield[a]在转换为int型时是有符号的，
        //因此，我们在其值大于7F时，需要做相应的转换处理。
        crc =crc ^ ( (int)crcBuff[a]>=0 ? crcBuff[a] : (crcBuff[a]+256) );
        for(j=0;j<8;j++)
        {
            k=crc & 01;//看crc的最低位是不是0，如果不是0，就与0xA001异或。
            crc = crc >> 1;
            if (k==0) continue;
            crc =crc ^ 0xA001;
        }
    }
    crcValue =crc%256;
    m_uCrcValue=(crcValue<<8)&0xff00;
    crcValue =crc/256;
    m_uCrcValue=m_uCrcValue|((crcValue)&0x00ff);
    return m_uCrcValue;    //将整数返回,这里是个十进制数
}

bool Widget::DataCrcCheck(char *DataBuff, ulong m_ulen)
{
    if(DataBuff==NULL||m_ulen<=2)
        return false;
    uint m_CrcLow,m_CrcHig;
    ulong m_uCrcValue=0;
    m_uCrcValue = CRCCheck(DataBuff,m_ulen - 2);
    m_CrcHig=(m_uCrcValue)>>8&0xff;
    m_CrcLow=m_uCrcValue&0xff;
    //qDebug()<<m_CrcHig<<m_CrcLow<<"CRChL";
    //判断CRC是否正确
    if( m_CrcLow==(uchar)DataBuff[m_ulen - 1]&&m_CrcHig == (uchar)DataBuff[m_ulen - 2] )
    {
        qDebug()<< "CRC ok!";
        return true;
    }
    else
    {
        qDebug()<<"CRC error";
        return false;
    }
    return false;
}

void Widget::SendModData(qint64 Data,qint64 IsSaveState,int Counter)
{
    uint m_CrcLow = 0,m_CrcHig = 0;//存放CRC高低位
    char SendData[10]={0};//存放发送缓冲数据
    SendData[0]=0x01;//modbus 地址位
    SendData[1]=0x01;//功能位
    SendData[2]=Data;//控制位
    SendData[3] = IsSaveState;//是否存储状态
    SendData[4]=Counter;

    ulong m_uCrcValue=0;//crc校验返回值
    m_uCrcValue = CRCCheck(SendData,5);//CRC校验
    //取出CRC高地位
    m_CrcHig=m_uCrcValue>>8&0xff;
    m_CrcLow=m_uCrcValue&0xff;
    //将CRC高低位放入缓冲
    SendData[5]=m_CrcHig;
    SendData[6]=m_CrcLow;

    //判断mainwindow和pser_com两个对象均已创建
    if( pMainWnd!=NULL)
    if( pMainWnd->pSer_Com!=NULL)
    //然后即可用调用mainwindow下pserCOM对象的函数发送数据
    //                 for(int i =0;i<7;i++)
    //                     qDebug("%d",(uchar)SendData[i]);
    pMainWnd->pSer_Com->SendData(SendData,10);
    qDebug("%c",SendData[5]);
}
