#ifndef CONFI_H
#define CONFI_H
#include <QObject>

#define QueuenSize 50
#define BuffSize 55

typedef struct//缓存队列
{
    char DataBuff[BuffSize];
    int  Len;
}Comdata,*pComdata;

typedef struct
{
    char name[10];   //姓名
    char ID[12];    //身份证号
    char carID[10];  //车牌
    char stWeight;  //额重
    char ADWeight;    //实际重量
}carDis;

extern void PutDataIntoQueuen(pComdata pData);
extern bool GetDataFromQueuen(pComdata pData);
extern qint64 SendControlData;
extern qint64 SendIsSaveState;

#endif // CONFI_H
