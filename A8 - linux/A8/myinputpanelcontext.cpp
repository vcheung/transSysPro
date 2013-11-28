/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore>

#include "myinputpanelcontext.h"
#include <QKeyEvent>
//#include <QDebug>

//! [0]

MyInputPanelContext::MyInputPanelContext()
{
    inputPanel = new MyInputPanel;
    connect(inputPanel, SIGNAL(characterGenerated(QChar)), SLOT(sendCharacter(QChar)));
    connect(inputPanel,SIGNAL(BackSpaceSignal()),this,SLOT(BackSpaceSlot()));
    connect(inputPanel,SIGNAL(EnterSignal()),this,SLOT(EnterSlot()));
}

//! [0]

MyInputPanelContext::~MyInputPanelContext()
{
    delete inputPanel;
}

//! [1]

bool MyInputPanelContext::filterEvent(const QEvent* event)
{
    if (event->type() == QEvent::RequestSoftwareInputPanel) {
        //#当某个Widget请求软键盘输入时，显示软键盘
        updatePosition();
        inputPanel->show();
        return true;
    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
        inputPanel->hide();
        return true;
    }
    return false;
}

//! [1]

QString MyInputPanelContext::identifierName()
{
    return "MyInputPanelContext";
}

void MyInputPanelContext::reset()
{
}

bool MyInputPanelContext::isComposing() const
{
    return false;
}

QString MyInputPanelContext::language()
{
    return "en_US";
}

//! [2]

void MyInputPanelContext::sendCharacter(QChar character)
{
    QPointer<QWidget> w = focusWidget();
    if (!w)
        return;

    //当收到按键面板的按键输入后，分别向当前焦点Widget发送KeyPress和KeyRelease事件
    QKeyEvent keyPress(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString(character));
    QApplication::sendEvent(w, &keyPress);

    if (!w)
        return;

    QKeyEvent keyRelease(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString());
    QApplication::sendEvent(w, &keyRelease);
}

//! [2]

//! [3]

void MyInputPanelContext::updatePosition()
{
    QWidget *widget = focusWidget();
    if (!widget)
        return;

    QRect widgetRect = widget->rect();
    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom());
    panelPos = widget->mapToGlobal(panelPos);

    int tempx = 200 - panelPos.rx();
    if(panelPos.rx()>200)//判断键盘界面是否超出整个界面，如超出则改动坐标x
        panelPos.rx() = panelPos.rx()+tempx;
    int tempy = 370 - panelPos.ry();
    if(panelPos.ry()>370)//判断键盘界面是否超出整个界面，如超出则改动坐标y
        panelPos.ry() = panelPos.ry()+tempy-140;

    inputPanel->move(panelPos);
}

void MyInputPanelContext::BackSpaceSlot()
{

    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;
    QKeyEvent keyPress(QEvent::KeyPress,0x01000003, Qt::NoModifier);
    QApplication::sendEvent(w, &keyPress);




}

void MyInputPanelContext::EnterSlot()
{
    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;
    QKeyEvent keyPress(QEvent::KeyPress,0x01000005, Qt::NoModifier);
    QApplication::sendEvent(w, &keyPress);

}

//! [3]
