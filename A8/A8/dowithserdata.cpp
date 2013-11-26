#include "dowithserdata.h"

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

//dowithserdata::dowithserdata()
//{
//}
