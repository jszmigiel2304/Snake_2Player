#include "w_mainwindow.h"
#include "c_myqapplication.h"
#include "c_game.h"
#include "c_board.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    c_MyQApplication a(argc, argv);    
    w_MainWindow w(a.getWindowProperties());

    c_game game;


    QObject::connect(&a, SIGNAL(changeMoveDirectionKeysPressed(QList<int>)), &game, SLOT(changeMoveDirection(QList<int>)));

    QObject::connect( &game, SIGNAL(stopGameSignal()), &w, SLOT(stopRefreshing()));

    QObject::connect( &game.getPlayer1(), SIGNAL(boardChangedSignal(const board::boardArray &, const c_snake &)), &w, SLOT(refreshPlayer1Board(const board::boardArray &, const c_snake &)));
    QObject::connect( &game.getPlayer2(), SIGNAL(boardChangedSignal(const board::boardArray &, const c_snake &)), &w, SLOT(refreshPlayer2Board(const board::boardArray &, const c_snake &)));

    QObject::connect( game.getEventCtrlr(), SIGNAL(speedUpTimerStartedSignal(QPair<bool, bool>, int)), &w, SLOT(refrshSpeedUpCounter(QPair<bool, bool>, int)));
    QObject::connect( game.getEventCtrlr(), SIGNAL(speedUpTimerOneSecPassedSignal(QPair<bool, bool>, int)), &w, SLOT(refrshSpeedUpCounter(QPair<bool, bool>, int)));
    QObject::connect( &game, SIGNAL(speedUpSignal(QPair<bool, bool>, quint8)), &w, SLOT(refreshSpeedUpCounterLevelLabel(QPair<bool, bool>, quint8)));

    QObject::connect( game.getPlayer1().getWallet(), SIGNAL(walletValueChanged(qint32)), &w, SLOT(refreshPlayer1Coins(qint32)));
    QObject::connect( game.getPlayer2().getWallet(), SIGNAL(walletValueChanged(qint32)), &w, SLOT(refreshPlayer2Coins(qint32)));


    QObject::connect(&game, SIGNAL(notificationMessage(QPair<bool, bool>, QString)), &w, SLOT(showNotification(QPair<bool, bool>, QString)) );


    w.loadPlayer1Board( game.getPlayer1().getBoard()->getBoard() );
    w.loadPlayer2Board( game.getPlayer2().getBoard()->getBoard() );

    w.loadPlayer1Snake(game.getPlayer1().getSnake());
    w.loadPlayer2Snake(game.getPlayer2().getSnake());

    w.show();
    return a.exec();
}
