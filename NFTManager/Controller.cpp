#include "Controller.h"
#include <QDebug>
#include <QTimer>
#include "NFTables.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    setListening(false);
}

Controller::~Controller()
{
    NFTables::cleanupTcpUdpNFTables();
}

void Controller::debug()
{
    qDebug() << "[DEBUG] Whatever this is, I guess it is working!";
    updateTcpUdpCount();
}

void Controller::updateTcpUdpCount()
{
    if (!m_listening)
    {
        setListening(true);
        NFTables counter;

        NFTables::setupTcpUdpNFTables();
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&Controller::getTcpUdpCount));
        timer->setSingleShot(true);
        timer->start(10000);
    }
    else{
        qDebug() << "Module is already listening!";
    }
}

void Controller::getTcpUdpCount()
{
    setListening(false);
    TcpUdpCount output = NFTables::getTcpUdpCounters();
    setInTcpCount(output.tcpCount);
    setInUdpCount(output.udpCount);
    qDebug() << "Tcp count: " << m_inTcpCount;
    qDebug() << "Udp count: " << m_inUdpCount;
}

int Controller::inUdpCount() const
{
    return m_inUdpCount;
}

void Controller::setInUdpCount(int newInUdpCount)
{
    if (m_inUdpCount == newInUdpCount)
        return;
    m_inUdpCount = newInUdpCount;
    emit inUdpCountChanged();
}

int Controller::inTcpCount() const
{
    return m_inTcpCount;
}

void Controller::setInTcpCount(int newInTcpCount)
{
    if (m_inTcpCount == newInTcpCount)
        return;
    m_inTcpCount = newInTcpCount;
    emit inTcpCountChanged();
}

bool Controller::listening() const
{
    return m_listening;
}

void Controller::setListening(bool newListening)
{
    if (m_listening == newListening)
        return;
    m_listening = newListening;
    emit listeningChanged();
}
