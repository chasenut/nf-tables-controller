#include "Controller.h"
#include <QDebug>
#include <QTimer>
#include "NFTables.h"
#include "Utilities.h"
#include <QStringList>

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    //setListening(false);
    //Utilities::resetNFTablesConfigFileToDefault();
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

void Controller::toogleBlockAllPackets()
{
    QStringList nftBlockAllContent = {
        //"table inet block_all {;   chain input {;       type filter hook input priority 0; policy drop; }; }"
        "table inet block_all {;   chain input {;       type filter hook input priority 0; policy drop;       iif lo accept; }; }"
    };
    //std::string nftBlockAll = "table inet block_all { chain input { type filter hook input priority 0; policy drop; } }";

    if (!m_blockedAllInPackets)
    {
        for (const auto& cmd : nftBlockAllContent)
        {
            Utilities::addLineToFile(NFTables::NFTConfigPath, cmd.toStdString());
        }
        //Utilities::addLineToFile(NFTables::NFTConfigPath, nftBlockAll);
    }
    else
    {
        for (const auto& cmd : nftBlockAllContent)
        {
            Utilities::removeLineContainingFromFile(NFTables::NFTConfigPath, cmd.toStdString());
        }
        //Utilities::removeLineContainingFromFile(NFTables::NFTConfigPath, nftBlockAll);
    }

    NFTables::reloadNFT();
    setBlockedAllInPackets(!m_blockedAllInPackets);
}

void Controller::resetNFT(const bool& hard)
{
    Utilities::resetNFTablesConfigFileToDefault();
    if (hard)
        system("sudo nft flush ruleset");
    NFTables::reloadNFT();
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

bool Controller::blockedAllInPackets() const
{
    return m_blockedAllInPackets;
}

void Controller::setBlockedAllInPackets(bool newBlockedAllInPackets)
{
    if (m_blockedAllInPackets == newBlockedAllInPackets)
        return;
    m_blockedAllInPackets = newBlockedAllInPackets;
    emit blockedAllInPacketsChanged();
}
