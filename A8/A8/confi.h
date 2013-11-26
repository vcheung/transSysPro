#ifndef CONFI_H
#define CONFI_H
#include <QObject>

#define QueuenSize 50
#define BuffSize 55

typedef struct//ª∫¥Ê∂”¡–
{
    char DataBuff[BuffSize];
    int  Len;
}Comdata,*pComdata;

extern void PutDataIntoQueuen(pComdata pData);
extern bool GetDataFromQueuen(pComdata pData);
extern qint64 SendControlData;
extern qint64 SendIsSaveState;

#endif // CONFI_H
