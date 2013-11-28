#ifndef XMLFILE_H
#define XMLFILE_H

#include <QtXml/qdom.h>
#include <QFile>
#include <QTextStream>
//#include "workwidget.h"
#include "confi.h"
#include <QString>

//namespace Ui {
//class workwidget;
//}

class xmlfile : public QObject
{
    Q_OBJECT

public:
    xmlfile(QString mFileName);
    void writeFile(carDis xml_mcarDis);
//    void showFile();
    QString FileName;
    bool sameOrNot(carDis judge_mcarDis);

private:
//    Ui::workwidget *pui;
//    QDomElement root;
};

#endif // XMLFILE_H
