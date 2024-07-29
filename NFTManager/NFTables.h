#ifndef NFTABLES_H
#define NFTABLES_H

#include <QObject>
#include <QString>

struct TcpUdpCount
{
    int tcpCount;
    int udpCount;
};

class NFTables
{
public:
    NFTables();
    static const std::string NFTConfigPath;

    static void setupTcpUdpNFTables();
    static void cleanupTcpUdpNFTables();
    static void reloadNFT();

public slots:
    static TcpUdpCount getTcpUdpCounters();

private:
    static int extractCounterValue(const QString& output, const QString& counterName);
};

#endif // NFTABLES_H
