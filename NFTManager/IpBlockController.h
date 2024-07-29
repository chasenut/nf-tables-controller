#ifndef IPBLOCKCONTROLLER_H
#define IPBLOCKCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>

#include "IpBlockInfo.h" // IF ANY ERROR, TRY TO SWITCH THIS COMMENT AND UNCOMMENT LINE BELOW
//class IpBlockInfo;

class IpBlockController : public QAbstractListModel
{
    Q_OBJECT
public:
    enum IpBlockRole {
        IpBlockIpAddressRole = Qt::UserRole + 1,
        IpBlockIdRole
    };

    explicit IpBlockController(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void addItem(const QString& ipAddress);
    void removeItem(const QString& ipAddress);

    QString parseIpToId(const QString& ipAddress);

signals:


private:
    QList<IpBlockInfo*> m_ipBlockList;
};

#endif // IPBLOCKCONTROLLER_H
