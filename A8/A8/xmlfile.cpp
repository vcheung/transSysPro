#include "xmlfile.h"
//#include "ui_workwidget.h"
#include <stdlib.h>
#include <QDebug>

xmlfile::xmlfile(QString mFileName)
{
    FileName = mFileName;
}

void xmlfile::writeFile(carDis xml_mcarDis)
{
    QFile file(FileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;

    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(tr("车辆基本信息"));
    doc.appendChild(root);

    QDomElement basic = doc.createElement(tr("车辆基本信息"));
    QDomElement drID = doc.createElement(tr("身份证号码"));
    QDomElement name = doc.createElement(tr("司机姓名"));
    QDomAttr carID = doc.createAttribute(tr("车牌号码"));
    QDomElement stWeight = doc.createElement(tr("额定载重"));
    QDomElement ADWeight = doc.createElement(tr("实际载重"));
    QDomText text;

    carID.setValue(tr(xml_mcarDis.carID));
    basic.setAttributeNode(carID);
    text = doc.createTextNode(tr(xml_mcarDis.name));
    name.appendChild(text);
    text = doc.createTextNode(tr(xml_mcarDis.ID));
    drID.appendChild(text);


    char *mstWeight;
    _itoa((int)xml_mcarDis.stWeight,mstWeight,10);
    char *mADWeight;
    _itoa((int)xml_mcarDis.ADWeight,mADWeight,10);


    text = doc.createTextNode(tr(mstWeight));
    stWeight.appendChild(text);
    text = doc.createTextNode(tr(mADWeight));
    ADWeight.appendChild(text);

    basic.appendChild(name);
    basic.appendChild(drID);
    basic.appendChild(stWeight);
    basic.appendChild(ADWeight);
    root.appendChild(basic);

    QTextStream out(&file);
    doc.save(out,4);
    file.close();
//    qDebug()<<"write xml";
}

//void xmlfile::showFile()
//{
//    pui->listWidget->clear();
//    QFile file(FileName);
//    if(!file.open(QIODevice::ReadOnly))
//        return;
//    QDomDocument doc;
//    if(!doc.setContent(&file))
//    {
//        file.close();
//        return;
//    }
//    file.close();

//    QDomElement docElem = doc.documentElement();
//    QDomNode n = docElem.firstChild();
//    while(!n.isNull())
//    {
//        if(n.isElement())
//        {
//            QDomElement e = n.toElement();
//            pui->listWidget->addItem(e.tagName());
//            QDomNodeList list = e.childNodes();
//            for(int i=0;i<list.count();i++)
//            {
//                QDomNode node = list.at(i);
//                if(node.isElement())
//                    pui->listWidget->addItem(" "+node.toElement().tagName()
//                                            +":"+node.toElement().text());
//            }
//        }
//        n=n.nextSibling();
//    }
//}

bool xmlfile::sameOrNot(carDis judge_mcarDis)
{
    QFile file(FileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Truncate))
        return NULL;

    QDomDocument (doc);
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.lastChild();
    while(!n.isNull())
    {
        if(n.isElement())
        {
            QDomElement e = n.toElement();
            if(judge_mcarDis.carID == e.attribute("车牌号码"))
            {
                qDebug()<<"true";
                return true;
            }
            else
            {
                qDebug()<<"false3";
                return false;
            }
        }
        qDebug()<<"false2";
        return false;
    }
    qDebug()<<"false1";
    return false;
}
