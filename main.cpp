#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "changeColor.h"
#include <QMetaObject>
#include <QDebug>
#include <QColor>
#include <QVariant>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *root = NULL;
    QList<QObject*> rootObjects = engine.rootObjects();
    int count = rootObjects.size();
    for(int i=0;i<count;i++)
    {
        if(rootObjects.at(i)->objectName() == "rootObject")
        {//寻找到对象名称为rootObject的qml对象

            root = rootObjects.at(i);
            break;
        }
    }

    new ChangeQmlColor(root);
    //寻找到root对象的子对象，其名称为quitButton,并与槽函数对应起来
    QObject *quitButton = root->findChild<QObject*>("quitButton");
    if(quitButton)
    {
        QObject::connect(quitButton,SIGNAL(clicked()),&app,SLOT(quit()));

    }

    QObject *textLabel = root->findChild<QObject*>("textLabel");
    if(textLabel)
    {
        //1. failed call,返回可用的方法
        bool bRet = QMetaObject::invokeMethod(textLabel,"setText",Q_ARG(QString,"world hello"));
        qDebug() << "call setText return - " << bRet;//不存在该方法
        textLabel ->setProperty("color",QColor::fromRgb(255,0,0));
        bRet = QMetaObject::invokeMethod(textLabel,"doLayout");//该方法存在
        qDebug() << "call doLayout return -" << bRet;
    }


    return app.exec();
}
