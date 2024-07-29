#include "NFTables.h"
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <fstream>
#include <filesystem>
#include <QTimer>
#include <string>
#include <algorithm>

std::string const NFTables::NFTConfigPath = "/etc/nftables.conf";

NFTables::NFTables() {}



TcpUdpCount NFTables::getTcpUdpCounters()
{
    QString output = "";
    std::string filePath = "commandOutputData.kupagowna";
    system(("sudo nft list counters >> " + filePath).c_str());

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        qDebug() << "[ERROR] Failed to read and write tcp/udp counters data!";
        return {0, 0};
    }

    std::string line;
    while (std::getline(file, line))
        output += QString::fromStdString(line);

    file.close();
    std::filesystem::remove(filePath);
    cleanupTcpUdpNFTables();

    TcpUdpCount result;
    result.tcpCount = extractCounterValue(output, "tcp_counter");
    result.udpCount = extractCounterValue(output, "udp_counter");


    return result;
}

void NFTables::setupTcpUdpNFTables()
{
    QStringList commands = {
        "sudo nft add table inet packet_count",
        "sudo nft add counter inet packet_count tcp_counter",

        "sudo nft add chain inet packet_count input { type filter hook input priority 0 \\; }",
        "sudo nft add rule inet packet_count input tcp dport { 0-65535 } counter name tcp_counter",

        "sudo nft add counter inet packet_count udp_counter",
        "sudo nft add rule inet packet_count input udp dport { 0-65535 } counter name udp_counter"
    };

    for (const QString& cmd : commands)
    {
        system(cmd.toStdString().c_str());
    }
}

void NFTables::cleanupTcpUdpNFTables()
{
    QStringList commands = {
        "sudo nft delete table inet packet_count"
    };

    for (const QString &cmd : commands) {
        system(cmd.toStdString().c_str());
    }
}

void NFTables::reloadNFT()
{
    std::string command = "sudo nft -f " + NFTConfigPath;
    system(command.c_str());
}

int NFTables::extractCounterValue(const QString &output, const QString &counterName)
{
    QStringList lines = output.split('\n');
    for (const auto& line : lines)
    {
        if (line.contains(counterName))
        {
            QStringList words = line.split(' ', Qt::SkipEmptyParts);
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i] == counterName)
                {
                    return words[i + 2].toInt();
                }
            }
            // std::string napis = line.toStdString();
            // auto found = std::find(napis.begin(), napis.end(), counterName.toStdString());
            // if (found != napis.end())
            // {
            //     return words[found - napis.begin() + 2].toInt();
            // }
        }
    }
    return 0;
}
