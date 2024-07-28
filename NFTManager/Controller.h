#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int inTcpCount READ inTcpCount WRITE setInTcpCount NOTIFY inTcpCountChanged FINAL)
    Q_PROPERTY(int inUdpCount READ inUdpCount WRITE setInUdpCount NOTIFY inUdpCountChanged FINAL)
    Q_PROPERTY(bool listening READ listening WRITE setListening NOTIFY listeningChanged FINAL)

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    int inUdpCount() const;
    void setInUdpCount(int newInUdpCount);

    int inTcpCount() const;
    void setInTcpCount(int newInTcpCount);

    bool listening() const;
    void setListening(bool newListening);

public slots:
    void debug();
    void updateTcpUdpCount();
    void getTcpUdpCount();


signals:

    void inUdpCountChanged();

    void inTcpCountChanged();

    void listeningChanged();

private:

    int m_inUdpCount = 0;
    int m_inTcpCount = 0;
    bool m_listening;
};

#endif // CONTROLLER_H
