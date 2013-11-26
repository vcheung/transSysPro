#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QWidget>
#include "confi.h"

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

public slots:
    void updatetime();
    void updateShowSlot();

private slots:
    void on_returnWork_clicked();

private:
    Ui::workwidget *ui;
    int m_type;
    carDis W_mcarDis;

signals:
    void switchToManSignal();
    void updateShowSignal();
};

#endif // WORKWIDGET_H
