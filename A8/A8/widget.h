#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "workwidget.h"
#include "secretinput.h"
#include "confi.h"

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

public slots:
    void updatetime();
    void magWorkWShow();
    void workWShow();
    void toSecret();
    void manShow();

private:
    Ui::Widget *ui;

signals:
    void switchToWorkWSignal();
    void switchToSecretSignal();

private slots:
    void on_visiBtn_clicked();
    void on_manaBtn_clicked();
};

#endif // WIDGET_H
