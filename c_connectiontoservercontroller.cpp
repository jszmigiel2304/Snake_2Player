#include "c_connectiontoservercontroller.h"
#include "c_parser.h"

c_connectionToServerController::c_connectionToServerController(QObject *parent)
    : QObject{parent}
{
    socket.setParent(this);
    host = QHostAddress(server::addres);
    port = server::port;

    connect(&socket, SIGNAL(connected()), this, SLOT(peerConnected()));
    connect(&socket, SIGNAL(disconnected()), this, SLOT(peerDisconnected()));
    connect(&socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(peerErrorOccurred(QAbstractSocket::SocketError)));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(peerReadyRead()));
    connect(this, SIGNAL(dataReceived(QByteArray)), this, SLOT(processReceivedData(QByteArray)));
    connect(this, SIGNAL(readingPacketErrorSignal()), this, SLOT(readingPacketError()));
}

c_connectionToServerController::~c_connectionToServerController()
{
    if(socket.state() == QAbstractSocket::ConnectedState)
    {
        socket.disconnectFromHost();
    }
}


void c_connectionToServerController::sendToServer(const QByteArray &data)
{
    socket.write(data);
    writeEndOfPacket();
    socket.waitForBytesWritten();
}

QAbstractSocket::SocketState c_connectionToServerController::getConnectionStatus()
{
    return socket.state();
}

void c_connectionToServerController::connectToServer()
{
    socket.connectToHost(host, port);
    socket.waitForConnected();

    if(socket.state() == QAbstractSocket::ConnectedState) {

    }

}


const QTcpSocket &c_connectionToServerController::getSocket() const
{
    return socket;
}

void c_connectionToServerController::peerConnected()
{
}

void c_connectionToServerController::peerDisconnected()
{
    emit connectionFinished(this);
}

void c_connectionToServerController::peerErrorOccurred(QAbstractSocket::SocketError error)
{

}

void c_connectionToServerController::peerReadyRead()
{
    while(socket.canReadLine()) {
        QByteArray data = socket.readLine();
        qDebug() << "Reading data... [ " << data.size() << " bytes]";

        emit dataReceived(data);
    }
}

void c_connectionToServerController::processReceivedData(QByteArray data)
{
    parser::Packet packet;
    c_parser().ParseReceivedPacket(data, packet);

    switch (packet.content) {
    case parser::EMPTY: { return;}
    case parser::ERROR_READING_JSON: { emit readingPacketErrorSignal(); return; }
    case parser::SET_PLAYER_NAME_ANSWER: { emit setPlayersNameAnswer(packet.data.at(0)["player_name"].toString()); return; }
    case parser::LOBBY_CREATED: { emit newLobbyRequestAnswer( lobby::lobbyInformations::fromMap( packet.data.at(0) ) ); return; }
    case parser::LOBBY_INFOS_CHANGED: { emit refreshLobbyInfoAnswer( lobby::lobbyInformations::fromMap( packet.data.at(0) ) ); return; }
    case parser::LOBBY_REMOVED: { emit lobbyRemovedAnswer( packet.data.at(0)["lobby_name"].toString()); return; }
    case parser::LOBBIES_LIST: {
        QList<lobby::lobbyInformations> lobbiesInfos;
        std::for_each( packet.data.begin(), packet.data.end(), [&lobbiesInfos](QMap<QString, QVariant> map) { lobbiesInfos.append( lobby::lobbyInformations::fromMap(map) );} );
        emit lobbiesListAnswer( lobbiesInfos );
        return; }
    default: {break;}
    }
}

void c_connectionToServerController::writeEndOfPacket()
{
    const char *eop {"\n"};
    socket.write(eop);
    socket.flush();
}

void c_connectionToServerController::readingPacketError()
{

}
