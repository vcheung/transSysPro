#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include "myinputpanelcontext.h"

MyInputPanelContext *NumKey;

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QApplication a(argc, argv);

    NumKey = new MyInputPanelContext ;
    a.setInputContext(NumKey);

    Widget *w;
    w=new Widget;
    w->show();

    return a.exec();
}
