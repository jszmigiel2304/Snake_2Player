#ifndef C_GAME_H
#define C_GAME_H

#include "_myData.h"
#include "c_player.h"
#include "c_lobby.h"

#include <QObject>
#include <QList>
#include <QPoint>
#include <QSet>
#include <QTimer>
#include <QPair>
#include <QPointer>

class c_game : public QObject
{
    Q_OBJECT
public:
    explicit c_game(QObject *parent = nullptr);
    ~c_game();

public slots:
    void orderNewLobbyFromServer();
    void createLobby();
    void removeLobby();
    void refreshLobby(const lobby::lobbyInformations &lobbyInfo);

    void getLobbiesListFromServer();

private:
    QPointer<c_lobby> lobby;
    c_player player;

private slots:
    void lobbyChanged(const lobby::lobbyInformations &lobbyInfo);

signals:
    void orderNewLobbySignal(const QByteArray &packet);
    void lobbyCreated(const lobby::lobbyInformations &lobbyInfo);
    void lobbyRemoved();
    void lobbyChangedSignal(const lobby::lobbyInformations &lobbyInfo);
    void getLobbiesListSignal(const QByteArray &packet);

};

#endif // C_GAME_H
