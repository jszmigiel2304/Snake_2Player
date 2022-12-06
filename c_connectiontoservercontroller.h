#ifndef C_CONNECTIONTOSERVERCONTROLLER_H
#define C_CONNECTIONTOSERVERCONTROLLER_H

#include "_myData.h"

#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>

class c_connectionToServerController : public QObject
{
    Q_OBJECT
public:
    explicit c_connectionToServerController(QObject *parent = nullptr);
    ~c_connectionToServerController();

    const QTcpSocket &getSocket() const;


    QAbstractSocket::SocketState getConnectionStatus();
    QString toString();

public slots:
    void sendToServer(const QByteArray &data);
    void connectToServer();

protected:

private:
    QTcpSocket socket;
    QHostAddress host;
    quint16 port;

private slots:
    void peerConnected();
    void peerDisconnected();
    void peerErrorOccurred(QAbstractSocket::SocketError error);
    void peerReadyRead();

    void processReceivedData(QByteArray data);

    void writeEndOfPacket();
    void readingPacketError();

signals:
    void connectionFinished(c_connectionToServerController *client);

    void dataReceived(QByteArray data);
    void readingPacketErrorSignal();

    void setPlayersNameAnswer(const QString &name);
    void newLobbyRequestAnswer(const lobby::lobbyInformations &lobbyInfo);
    void refreshLobbyInfoAnswer(const lobby::lobbyInformations &lobbyInfo);
    void lobbyRemovedAnswer(const QString &lobbyName);
    void lobbiesListAnswer(const QList<lobby::lobbyInformations> &lobbiesInfo);
};

#endif // C_CONNECTIONTOSERVERCONTROLLER_H
