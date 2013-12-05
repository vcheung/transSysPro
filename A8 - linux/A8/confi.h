#ifndef CONFI_H
#define CONFI_H
#include <QObject>

#define QueuenSize 50
#define BuffSize 55

typedef struct//�������
{
    char DataBuff[BuffSize];
    int  Len;
}Comdata,*pComdata;

typedef struct
{
    char name[10];   //����
    char ID[12];    //����֤��
    char carID[10];  //����
    char stWeight;  //����
    char ADWeight;    //ʵ������
}carDis;

extern void PutDataIntoQueuen(pComdata pData);
extern bool GetDataFromQueuen(pComdata pData);
extern qint64 SendControlData;
extern qint64 SendIsSaveState;

#endif // CONFI_H