#ifndef C_LOBBY_H
#define C_LOBBY_H

#include "_myData.h"
#include "c_player.h"

#include <QObject>


class c_lobby : public QObject
{
    Q_OBJECT
public:
    explicit c_lobby(QObject *parent = nullptr);
    ~c_lobby();

    const lobby::lobbyInformations &getLobbyInformations() const;
    void setLobbyInformations(const lobby::lobbyInformations &newLobbyInformations);

public slots:
    void refreshLobbyInfo(const lobby::lobbyInformations &lobbyInfo);

private:
    lobby::lobbyInformations lobbyInformations;

private slots:

signals:
    void propertiesChanged(const lobby::lobbyInformations &lobbyInfo);

};

#endif // C_LOBBY_H
