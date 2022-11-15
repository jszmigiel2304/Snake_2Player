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

    w.loadPlayer1Board( game.getBoardPlayer1()->getBoard() );
    w.loadPlayer2Board( game.getBoardPlayer2()->getBoard() );

    w.loadPlayer1Snake(game.getSnakePlayer1());
    w.loadPlayer2Snake(game.getSnakePlayer2());

    w.show();
    return a.exec();
}

