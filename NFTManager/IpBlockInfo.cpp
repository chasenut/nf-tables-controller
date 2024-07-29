#include "IpBlockInfo.h"
#include "Utilities.h"
#include "NFTables.h"

IpBlockInfo::IpBlockInfo(QObject *parent)
    : QObject{parent}
{
}

IpBlockInfo::~IpBlockInfo()
{
    Utilities::removeLineContainingFromFile(NFTables::NFTConfigPath, m_nft.toStdString());
}


QString IpBlockInfo::ipAddress() const
{
    return m_ipAddress;
}

void IpBlockInfo::setIpAddress(const QString &newIpAddress)
{
    if (m_ipAddress == newIpAddress)
        return;
    m_ipAddress = newIpAddress;
    emit ipAddressChanged();
}

QString IpBlockInfo::id() const
{
    return m_id;
}

void IpBlockInfo::setId(const QString &newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString IpBlockInfo::nft() const
{
    return m_nft;
}

void IpBlockInfo::setNft(const QString &newNft)
{
    if (m_nft == newNft)
        return;
    m_nft = newNft;
    emit nftChanged();
}
