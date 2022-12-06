#include "c_game.h"
#include "c_parser.h"

c_game::c_game(QObject *parent)
    : QObject{parent}
{
}


c_game::~c_game()
{
}

void c_game::orderNewLobbyFromServer()
{
    createLobby();
    emit orderNewLobbySignal( c_parser().prepareNewLobbyRequest(player.getName()) );
}

void c_game::createLobby()
{
    lobby = new c_lobby();
    if(lobby) {
        connect(lobby, SIGNAL(propertiesChanged(lobby::lobbyInformations)), this, SLOT(lobbyChanged(lobby::lobbyInformations)));
        emit lobbyCreated(lobby->getLobbyInformations());
    }
}

void c_game::removeLobby()
{
    lobby.data()->deleteLater();
    lobby.clear();

    if(lobby.isNull())
        emit lobbyRemoved();
}

void c_game::refreshLobby(const lobby::lobbyInformations &lobbyInfo)
{
    lobby->refreshLobbyInfo(lobbyInfo);
}

void c_game::getLobbiesListFromServer()
{
    emit getLobbiesListSignal( c_parser().prepareLobbiesListRequest() );
}

void c_game::lobbyChanged(const lobby::lobbyInformations &lobbyInfo)
{
    emit lobbyChangedSignal(lobbyInfo);
}






