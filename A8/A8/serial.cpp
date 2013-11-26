#include "serial.h"

serial::serial()
{
    pThread = NULL;
    m_curFun = NULL;
    m_bIsOpenFlag = false;
}

bool serial::Initcom(ComdataArrive m_pFun, QString m_sCom,
                BaudRateType m_eBaund, DataBitsType m_eDataBit,
                ParityType m_eParity, StopBitsType m_eStopbit,
                long m_lTimeOut, FlowType m_eFlowtype)
{
//    m_Com = new Posix_QextSerialPort(m_sCom, QextSerialBase::Polling);
    m_Com = new Win_QextSerialPort(m_sCom, QextSerialBase::Polling);
    m_bIsOpenFlag = m_Com->open(QIODevice::ReadWrite);
    if(m_pFun!=NULL)
        m_curFun = m_pFun;
    if(m_bIsOpenFlag)
    {
        m_Com->setBaudRate(m_eBaund);
        m_Com->setDataBits(m_eDataBit);
        m_Com->setParity(m_eParity);
        m_Com->setStopBits(m_eStopbit);
        m_Com->setFlowControl(m_eFlowtype);
        m_Com->setTimeout(m_lTimeOut);
        startSerThread();   //打开串口线程
    }
    return m_bIsOpenFlag;
}

void serial::startSerThread()
{
    if(pThread==NULL)
    {
        pThread = new serialThread(this);
        pThread->start();
    }
}

void serial::ReadData()
{
    if(m_Com!=NULL)
    {
        if(m_Com->bytesAvailable() >0)
        {
            QByteArray m_cBuff=m_Com->readAll();
            //#m_Com->readAll()_Reads all available data from the device, and returns it as a QByteArray.(from F1)

            //qDebug()<<"*******原始数据***********"<<m_cBuff;
            char *m_data=m_cBuff.data();
            //qDebug()<<"******读串口原始数据HEX************"<<m_cBuff.toHex();
            if(m_curFun!=NULL)      //#判断指针是否空__*缓冲队列
            m_curFun(m_data,m_cBuff.size());    //调用ComDataArriveOK(char *DataBuff, ulong m_ulen)
        }
    }
}

void serial::SendData(char *DataBuff, uint m_uSize)
{
    if(m_Com!=NULL && m_bIsOpenFlag && m_uSize>0 && DataBuff!=NULL)
        m_Com->write(DataBuff,m_uSize);
}

/********** 串口线程 **********/
serialThread::serialThread(serial *m_pSerCom)
{
    pSerCom=NULL;
    m_bIsRunFlag = false;
    if(m_pSerCom!=NULL)
        pSerCom = m_pSerCom;
}

void serialThread::run()
{
    while(!m_bIsRunFlag)
    {
        if(pSerCom!=NULL)
            pSerCom->ReadData();
    }
}
