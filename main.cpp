#include "w_mainwindow.h"
#include "c_myqapplication.h"
#include "c_connectiontoservercontroller.h"
#include "c_player.h"
#include "c_game.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    c_MyQApplication a(argc, argv);    
    w_MainWindow w(a.getWindowProperties());

    c_game game;


    c_connectionToServerController connection;

    QObject::connect(&game, SIGNAL(lobbyCreated(lobby::lobbyInformations)), &w, SLOT(refreshLobbyBox(lobby::lobbyInformations)));
    QObject::connect(&game, SIGNAL(lobbyChangedSignal(lobby::lobbyInformations)), &w, SLOT(refreshLobbyBox(lobby::lobbyInformations)));
    QObject::connect(&game, SIGNAL(orderNewLobbySignal(QByteArray)), &connection, SLOT(sendToServer(QByteArray)));
    QObject::connect(&game, SIGNAL(getLobbiesListSignal(QByteArray)), &connection, SLOT(sendToServer(QByteArray)));

    //QObject::connect(&game, SIGNAL(), ,SLOT());

    QObject::connect(&w, SIGNAL(newGameButtonPressed()), &game, SLOT(orderNewLobbyFromServer()));
    QObject::connect(&w, SIGNAL(newGameButtonPressed()), &game, SLOT(getLobbiesListFromServer()));

    QObject::connect(&connection, SIGNAL(newLobbyRequestAnswer(lobby::lobbyInformations)), &game, SLOT(refreshLobby(lobby::lobbyInformations)));
    QObject::connect(&connection, SIGNAL(lobbiesListAnswer(const QList<lobby::lobbyInformations> &)), &w, SLOT(refreshLobbiesListBox(const QList<lobby::lobbyInformations> &)));

//    QObject::connect(&lobby, SIGNAL(propertiesChanged(lobby::lobbyInformations)), &w, SLOT(refreshLobbyBox(lobby::lobbyInformations)));
//    QObject::connect(&lobby, SIGNAL(), &w, SLOT());


    connection.connectToServer();
    w.show();

    return a.exec();
}
