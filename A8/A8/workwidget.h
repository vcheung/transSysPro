#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QWidget>
#include "confi.h"
#include "xmlfile.h"
//#include <QtXml/qdom.h>
//#include <QFile>
//#include <QTextStream>

namespace Ui {
class workwidget;
}

class workwidget : public QWidget
{
    Q_OBJECT

public:
    explicit workwidget(int type=0,QWidget *parent = 0);
    ~workwidget();

    void showInf(carDis *pW_mcarDis);
    xmlfile *mxmlfile;

public slots:
    void updatetime();
    void updateShowSlot();
    void showList();

private slots:
    void on_returnWork_clicked();

    void on_quit_clicked();

private:
    Ui::workwidget *ui;
    int m_type;
    carDis W_mcarDis;

//    QFile file;

signals:
    void switchToManSignal();
    void updateShowSignal();
};

#endif // WORKWIDGET_H
