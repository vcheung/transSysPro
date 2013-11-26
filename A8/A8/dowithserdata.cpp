#include "dowithserdata.h"
#include "widget.h"
#include <QDebug>

extern Widget *pCommonPoint;

Comdata mtQueuen[QueuenSize];
QMutex DataMutex;
int m_intoCount=0,m_outCount=0;

qint64 SendControlData = 0;
qint64 SendIsSaveState = 0;

void PutDataIntoQueuen(pComdata pData)
{
    if(pData==NULL)
        return;
    DataMutex.lock();
    memcpy(&mtQueuen[m_intoCount++],pData,sizeof(Comdata));
    if(m_intoCount>=QueuenSize)
        m_intoCount=0;
    DataMutex.unlock();
}

bool GetDataFromQueuen(pComdata pData)
{
    bool m_bbSuccess=false;
    if(pData == NULL)
    return m_bbSuccess;
    memset(pData,0,sizeof(Comdata));
    DataMutex.lock();
    if(m_outCount!=m_intoCount)
   {
        memcpy(pData,&mtQueuen[m_outCount++],sizeof(Comdata));
        if(m_outCount>=QueuenSize)
            m_outCount=0;
        m_bbSuccess=true;
    }
    DataMutex.unlock();
    return  m_bbSuccess;
}

dowithserdata::dowithserdata()
{
    memset(&mcarDis,0,sizeof(carDis));
    m_bIsRunFlag = false;
    this->start();
}

dowithserdata::~dowithserdata()
{
}

void dowithserdata::run()
{
//    int IsSerBreak = 0;
    while (!m_bIsRunFlag)
    {
        memset(&m_dataBuf,0,sizeof(Comdata));
        if(GetDataFromQueuen(&m_dataBuf))
        {
            serDataAnalyzing(m_dataBuf);
            widgetShow();
            qDebug()<<"have got data from buffer";
        }
    }
}

void dowithserdata::serDataAnalyzing(Comdata mDataBuf)
{
    mcarDis.name[0] = mDataBuf.DataBuff[2];
    mcarDis.name[1] = mDataBuf.DataBuff[3];
    mcarDis.name[2] = mDataBuf.DataBuff[4];
    mcarDis.name[3] = mDataBuf.DataBuff[5];
    mcarDis.name[4] = mDataBuf.DataBuff[6];
    mcarDis.name[5] = mDataBuf.DataBuff[7];
    mcarDis.name[6] = mDataBuf.DataBuff[8];
    mcarDis.name[7] = mDataBuf.DataBuff[9];
    mcarDis.name[8] = mDataBuf.DataBuff[10];
    mcarDis.name[9] = mDataBuf.DataBuff[11];

    mcarDis.ID[0] = mDataBuf.DataBuff[12];
    mcarDis.ID[1] = mDataBuf.DataBuff[13];
    mcarDis.ID[2] = mDataBuf.DataBuff[14];
    mcarDis.ID[3] = mDataBuf.DataBuff[15];
    mcarDis.ID[4] = mDataBuf.DataBuff[16];
    mcarDis.ID[5] = mDataBuf.DataBuff[17];
    mcarDis.ID[6] = mDataBuf.DataBuff[18];
    mcarDis.ID[7] = mDataBuf.DataBuff[19];
    mcarDis.ID[8] = mDataBuf.DataBuff[20];
    mcarDis.ID[9] = mDataBuf.DataBuff[21];
    mcarDis.ID[10] = mDataBuf.DataBuff[22];
    mcarDis.ID[11] = mDataBuf.DataBuff[23];

    mcarDis.carID[0] = mDataBuf.DataBuff[24];
    mcarDis.carID[1] = mDataBuf.DataBuff[25];
    mcarDis.carID[2] = mDataBuf.DataBuff[26];
    mcarDis.carID[3] = mDataBuf.DataBuff[27];
    mcarDis.carID[4] = mDataBuf.DataBuff[28];
    mcarDis.carID[5] = mDataBuf.DataBuff[29];
    mcarDis.carID[6] = mDataBuf.DataBuff[30];
    mcarDis.carID[7] = mDataBuf.DataBuff[31];
    mcarDis.carID[7] = mDataBuf.DataBuff[32];
    mcarDis.carID[7] = mDataBuf.DataBuff[33];

    mcarDis.stWeight = mDataBuf.DataBuff[34];

    mcarDis.ADWeight = mDataBuf.DataBuff[35];
}

void dowithserdata::widgetShow()
{
    pCommonPoint->workW->showInf(&mcarDis);
    pCommonPoint->magWorkW->showInf(&mcarDis);
}
