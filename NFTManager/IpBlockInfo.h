#ifndef IPBLOCKINFO_H
#define IPBLOCKINFO_H

#include <QObject>
#include <qqml.h>

class IpBlockInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged FINAL)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString nft READ nft WRITE setNft NOTIFY nftChanged FINAL)
public:
    explicit IpBlockInfo(QObject *parent = nullptr);
    ~IpBlockInfo();


    QString ipAddress() const;
    void setIpAddress(const QString &newIpAddress);

    QString id() const;
    void setId(const QString &newId);

    QString nft() const;
    void setNft(const QString &newNft);

signals:

    void ipAddressChanged();

    void idChanged();

    void nftChanged();

private:

    QString m_ipAddress;
    QString m_id;
    QString m_nft;
};

#endif // IPBLOCKINFO_H
