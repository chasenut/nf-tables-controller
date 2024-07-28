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

    static void setupTcpUdpNFTables();
    static void cleanupTcpUdpNFTables();

public slots:
    static TcpUdpCount getTcpUdpCounters();

private:
    static int extractCounterValue(const QString& output, const QString& counterName);
};

#endif // NFTABLES_H
