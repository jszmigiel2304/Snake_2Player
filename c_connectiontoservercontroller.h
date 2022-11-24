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

    void write(QByteArray data);

    QAbstractSocket::SocketState getConnectionStatus();
    QString toString();

public slots:
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
    void newGameRequestAnswer(game::gameInformations gameInfo);
    void refreshGameInfoAnswer(game::gameInformations gameInfo);
    void gameRemovedAnswer(const QString &gameName);
    void gamesListAnswer(QList<game::gameInformations> gamesInfo);
};

#endif // C_CONNECTIONTOSERVERCONTROLLER_H
