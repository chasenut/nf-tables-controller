#include "IpBlockController.h"
#include "IpBlockInfo.h"
#include <algorithm>
#include "Utilities.h"
#include "NFTables.h"

IpBlockController::IpBlockController(QObject *parent)
    : QAbstractListModel{parent}
{}

int IpBlockController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_ipBlockList.length();
}

QVariant IpBlockController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_ipBlockList.length())
    {
        IpBlockInfo* ipBlockInfo = m_ipBlockList[index.row()];

        switch ((IpBlockRole) role) {
        case IpBlockIpAddressRole:
            return ipBlockInfo->ipAddress();
        case IpBlockIdRole:
            return ipBlockInfo->id();
        default:
            return {};
        }
    }
    return {};
}

QHash<int, QByteArray> IpBlockController::roleNames() const
{
    QHash<int, QByteArray> result;

    result[IpBlockIpAddressRole] = "ipBlockIpAddress";
    result[IpBlockIdRole] = "ipBlockId";

    return result;
}

void IpBlockController::addItem(const QString &ipAddress)
{
    if (!Utilities::isIpAddressValid(ipAddress))
    {
        qDebug() << "It is not a valid IP";
        return;
    }
    if (ipAddress == "")
    {
        qDebug() << "Cannot create empty object idiot";
        return;
    }

    QString id = parseIpToId(ipAddress);

    beginInsertRows(QModelIndex(), m_ipBlockList.length(), m_ipBlockList.length());

    IpBlockInfo *ipBlockInfo = new IpBlockInfo(this);

    std::string cmd = "table inet block_";

    cmd += id.toStdString();
    cmd += " {;   chain input {;       type filter hook input priority 0; policy accept;       ip saddr ";
    cmd += ipAddress.toStdString();
    cmd += " drop ; }; }";

    ipBlockInfo->setIpAddress(ipAddress);
    ipBlockInfo->setId(id);
    ipBlockInfo->setNft(QString::fromStdString(cmd));

    m_ipBlockList << ipBlockInfo;

    endInsertRows();

    Utilities::addLineToFile(NFTables::NFTConfigPath, cmd);
    NFTables::reloadNFT();
}

void IpBlockController::removeItem(const QString &ipAddress)
{
    for (int i = 0; i < m_ipBlockList.size(); i++)
    {
        if (m_ipBlockList[i]->ipAddress() == ipAddress)
        {
            beginRemoveRows(QModelIndex(), i, i);

            m_ipBlockList[i]->deleteLater();
            m_ipBlockList.removeAt(i);

            endRemoveRows();
        }
    }
}

QString IpBlockController::parseIpToId(const QString &ipAddress)
{
    std::string temp = ipAddress.toStdString();
    std::replace(temp.begin(), temp.end(), '.', '_');
    QString id = QString::fromStdString(temp);
    return id;
}
