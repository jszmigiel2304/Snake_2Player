#include "c_player.h"

c_player::c_player(QObject *parent)
    : QObject{parent}
{    
    board = new c_board(this);
    snake = new c_snake(this);
    wallet = new c_wallet(this);

    nextMoveDirection = snake::MOVE_UP;

    connect(board, SIGNAL(boardChanged()), this, SLOT(boardChanged()));
    connect(snake, SIGNAL(snakeChanged()), this, SLOT(snakeChanged()));
}

c_player::~c_player()
{
    wallet->deleteLater();
    board->deleteLater();
    snake->deleteLater();
}

c_board *c_player::getBoard() const
{
    return board;
}

void c_player::setBoard(c_board *newBoard)
{
    board = newBoard;
}

c_snake *c_player::getSnake() const
{
    return snake;
}

void c_player::setSnake(c_snake *newSnake)
{
    snake = newSnake;
}


void c_player::move()
{
    snake->move(getNextMoveDirection());
}

void c_player::speedUp(quint8 speedLevel)
{
    getSnake()->setSpeed(speedLevel);
}

void c_player::feedSnake(quint8 foodAmount)
{
    getSnake()->extend(foodAmount);
}

void c_player::coinsToWallet(quint32 coins)
{
    wallet->addCoins(coins);
}

void c_player::takeCoinsFromWallet(quint32 coins)
{
    wallet->takeCoins(coins);
}

c_wallet *c_player::getWallet() const
{
    return wallet;
}

snake::MoveDirection c_player::getNextMoveDirection() const
{
    return nextMoveDirection;
}

void c_player::setNextMoveDirection(snake::MoveDirection newNextMoveDirection)
{
    switch(newNextMoveDirection) {
    case snake::MOVE_UP: { if(getSnake()->getDirection() == snake::MOVE_DOWN) return; else break;}
    case snake::MOVE_DOWN: { if(getSnake()->getDirection() == snake::MOVE_UP)  return; else break;}
    case snake::MOVE_LEFT: { if(getSnake()->getDirection() == snake::MOVE_RIGHT)  return; else break;}
    case snake::MOVE_RIGHT: { if(getSnake()->getDirection() == snake::MOVE_LEFT)  return; else break;}
    }
    nextMoveDirection = newNextMoveDirection;
}

void c_player::boardChanged()
{
    emit boardChangedSignal(board->getBoard(), (*getSnake()));
}

void c_player::snakeChanged()
{
    nextMoveDirection = getSnake()->getDirection();
    emit potentialCollisionSignal( const_cast<QList<QPoint> &>(getSnake()->getSnake()), board->getBoard() );
    emit boardChangedSignal(board->getBoard(), (*getSnake()));
}

