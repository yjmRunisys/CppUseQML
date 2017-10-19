#include "changeColor.h"
#include <QDateTime>
#include <QColor>
#include <QVariant>

ChangeQmlColor::ChangeQmlColor(QObject *target, QObject *parent)
    :QObject(parent)
    ,m_timer(this)
    ,m_target(target)
{
    qsrand(QDateTime::currentDateTime().toTime_t());//随机数种子
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(onTimeout()));//连接
    m_timer.start(1000);//定时器超时后会自动发出timeout信号
}

ChangeQmlColor::~ChangeQmlColor()
{

}

void ChangeQmlColor::onTimeout()
{
    QColor color = QColor::fromRgb(qrand()%256,qrand()%256,qrand()%256);
    m_target->setProperty("color",color);
}
