#include "c_lobby.h"

c_lobby::c_lobby(QObject *parent)
    : QObject{parent}
{

}

c_lobby::~c_lobby()
{

}

void c_lobby::refreshLobbyInfo(const lobby::lobbyInformations &lobbyInfo)
{
    lobbyInformations = lobbyInfo;

    emit propertiesChanged(lobbyInformations);
}

const lobby::lobbyInformations &c_lobby::getLobbyInformations() const
{
    return lobbyInformations;
}

void c_lobby::setLobbyInformations(const lobby::lobbyInformations &newLobbyInformations)
{
    lobbyInformations = newLobbyInformations;
}
