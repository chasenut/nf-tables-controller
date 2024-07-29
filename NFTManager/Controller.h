#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int inTcpCount READ inTcpCount WRITE setInTcpCount NOTIFY inTcpCountChanged FINAL)
    Q_PROPERTY(int inUdpCount READ inUdpCount WRITE setInUdpCount NOTIFY inUdpCountChanged FINAL)
    Q_PROPERTY(bool listening READ listening WRITE setListening NOTIFY listeningChanged FINAL)
    Q_PROPERTY(bool blockedAllInPackets READ blockedAllInPackets WRITE setBlockedAllInPackets NOTIFY blockedAllInPacketsChanged FINAL)

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    int inUdpCount() const;
    void setInUdpCount(int newInUdpCount);

    int inTcpCount() const;
    void setInTcpCount(int newInTcpCount);

    bool listening() const;
    void setListening(bool newListening);

    bool blockedAllInPackets() const;
    void setBlockedAllInPackets(bool newBlockedAllInPackets);

public slots:
    void debug();
    void updateTcpUdpCount();
    void getTcpUdpCount();
    void toogleBlockAllPackets();
    void resetNFT(const bool& hard = false);


signals:

    void inUdpCountChanged();

    void inTcpCountChanged();

    void listeningChanged();

    void blockedAllInPacketsChanged();

private:

    int m_inUdpCount = 0;
    int m_inTcpCount = 0;
    bool m_listening = false;
    bool m_blockedAllInPackets = false;
};

#endif // CONTROLLER_H
