#ifndef DOWITHSERDATA_H
#define DOWITHSERDATA_H

#include "confi.h"
#include <QMutex>
#include <QString>
//#include "widget.h"
#include <QThread>

class dowithserdata:public QThread
{
    Q_OBJECT
public:
    dowithserdata();
    ~dowithserdata();

    void run();
    bool m_bIsRunFlag;  //线程标志
    void serDataAnalyzing(Comdata mDataBuf);
    void widgetShow();

    Comdata m_dataBuf;
    carDis mcarDis;
};

#endif // DOWITHSERDATA_H
