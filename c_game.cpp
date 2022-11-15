#include "c_game.h"

c_game::c_game(QObject *parent)
    : QObject{parent}
{
    boardPlayer1 = new c_board();
    boardPlayer2 = new c_board();

    snakePlayer1 = new c_snake();
    snakePlayer2 = new c_snake();
}

c_game::~c_game()
{
}


c_board *c_game::getBoardPlayer1() const
{
    return boardPlayer1;
}

c_board *c_game::getBoardPlayer2() const
{
    return boardPlayer2;
}

c_snake *c_game::getSnakePlayer1() const
{
    return snakePlayer1;
}

c_snake *c_game::getSnakePlayer2() const
{
    return snakePlayer2;
}


