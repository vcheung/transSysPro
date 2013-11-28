#ifndef SECRETINPUT_H
#define SECRETINPUT_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class secretInput;
}

class secretInput : public QWidget
{
    Q_OBJECT

public:
    explicit secretInput(QWidget *parent = 0);
    ~secretInput();
    QWidget *Prompter;
    void CreateErrorPrompter();

public slots:
    void switchToWorkwidget();
    void switchToMagWorkwidget();
    void invisiblePrompterSlot();

private:
    Ui::secretInput *ui;

signals:
    void switchToWorkwidgetSignal();
    void switchToMagWorkwidgetSignal();
};

#endif // SECRETINPUT_H
