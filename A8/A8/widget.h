#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "workwidget.h"
#include "secretinput.h"
#include "confi.h"
//#include "posix_qextserialport.h"
#include "win_qextserialport.h"
#include <QTimer>
#include "serial.h"
#include "dowithserdata.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    workwidget *workW;
    workwidget *magWorkW;
    secretInput *mageSecretInput;
    dowithserdata *pDoWithSerData;

    void serialManage();
    serial *pSer_Com;
    static void ComDataArriveOK(char *DataBuff,ulong m_ulen);
    ulong CRCCheck(char *crcBuff, ulong size);//CRCÐ£Ñé
    bool DataCrcCheck(char *DataBuff, ulong m_ulen);
    void SendModData(qint64 Data,qint64 IsSaveState,int Counter);

public slots:
    void updatetime();
    void magWorkWShow();
    void workWShow();
    void toSecret();
    void manShow();
    void SendModDataSlot();

signals:
    void switchToWorkWSignal();
    void switchToSecretSignal();

private slots:
    void on_visiBtn_clicked();
    void on_manaBtn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
