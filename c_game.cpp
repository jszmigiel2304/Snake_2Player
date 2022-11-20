#include "c_game.h"

c_game::c_game(QObject *parent)
    : QObject{parent}
{
    eventCtrlr = new c_eventController(this);
    speedLevel = 1;

    connect(eventCtrlr, SIGNAL(newBlockEvent(QPair<bool, bool> )), this, SLOT(addNewBlock(QPair<bool, bool> )));
    connect(eventCtrlr, SIGNAL(newFoodEvent(QPair<bool, bool> )), this, SLOT(addNewFood(QPair<bool, bool> )));
    connect(eventCtrlr, SIGNAL(newCoinEvent(QPair<bool, bool> )), this, SLOT(addNewCoin(QPair<bool, bool> )));
    connect(eventCtrlr, SIGNAL(moveEvent(QPair<bool, bool> )), this, SLOT(movePlayer(QPair<bool, bool> )));
    connect(eventCtrlr, SIGNAL(speedUpEvent(QPair<bool, bool>)), this, SLOT(speedUpPlayer(QPair<bool, bool>)), Qt::DirectConnection);

    connect(&player1, SIGNAL(potentialCollisionSignal(QList<QPoint> &, const board::boardArray &)), this, SLOT(testPotentialCollision(QList<QPoint> &, const board::boardArray &)), Qt::DirectConnection);
    connect(&player2, SIGNAL(potentialCollisionSignal(QList<QPoint> &, const board::boardArray &)), this, SLOT(testPotentialCollision(QList<QPoint> &, const board::boardArray &)), Qt::DirectConnection);

    connect(this, SIGNAL(stopGameSignal()), eventCtrlr, SLOT(stopTimers()), Qt::DirectConnection);
}


c_game::~c_game()
{
}


void c_game::changeMoveDirection(QList<int> keys)
{
    foreach (int key, keys) {
        switch (key) {
        case Qt::Key_W: {player1.setNextMoveDirection(snake::MOVE_UP); break;}
        case Qt::Key_S: {player1.setNextMoveDirection(snake::MOVE_DOWN); break;}
        case Qt::Key_A: {player1.setNextMoveDirection(snake::MOVE_LEFT); break;}
        case Qt::Key_D: {player1.setNextMoveDirection(snake::MOVE_RIGHT); break;}
        case Qt::Key_Up: {player2.setNextMoveDirection(snake::MOVE_UP); break;}
        case Qt::Key_Down: {player2.setNextMoveDirection(snake::MOVE_DOWN); break;}
        case Qt::Key_Left: {player2.setNextMoveDirection(snake::MOVE_LEFT); break;}
        case Qt::Key_Right: {player2.setNextMoveDirection(snake::MOVE_RIGHT); break;}
        default: {break;}
        }
    }
}

game::colisionResult c_game::testCollision(QList<QPoint> &snake, const board::boardArray &board)
{
    int x = snake.first().x();
    int y = snake.first().y();

    for(int iii = 1; iii<snake.size(); iii++)
        if(snake[iii].x() == x && snake[iii].y() == y)
            return game::SNAKE_BODY_COLLISION;

    board::BoardField field = board[x][y];

    if(static_cast<quint8>(field) == 0) return game::NO_COLLISION;
    else if(static_cast<quint8>(field) >= 1 && static_cast<quint8>(field) <= 2) return game::BLOCK_COLLISION;
    else if(static_cast<quint8>(field) >= 10 && static_cast<quint8>(field) <= 30) return game::SNAKE_BODY_COLLISION;
    else
        switch (field) {
        case board::FOOD_LVL_1: {
            return game::FOOD_LVL_1_COLLISION;
            break;
        }
        case board::FOOD_LVL_2: {
            return game::FOOD_LVL_2_COLLISION;
            break;
        }
        case board::COIN_LVL_1: {
            return game::COIN_LVL_1_COLLISION;
            break;
        }
        case board::COIN_LVL_2: {
            return game::COIN_LVL_2_COLLISION;
            break;
        }
        case board::COIN_LVL_3: {
            return game::COIN_LVL_3_COLLISION;
            break;
        }
        default:
            return game::UNDEFINED_COLLISION;
        }
}

void c_game::stopGame(QObject * loserPlayer)
{
    QPair<bool,bool> pair;
    if(loserPlayer == &player1)
        pair.first = true;
    if(loserPlayer == &player2)
        pair.second = true;

    emit stopGameSignal();
    emit notificationMessage(pair, "LOSS !!!");
}

c_eventController *c_game::getEventCtrlr() const
{
    return eventCtrlr;
}


void c_game::addNewBlock(QPair<bool, bool> player)
{
    if(player.first)
        player1.getBoard()->newBlock( player1.getSnake()->getSnake().first() );
    if(player.second)
        player2.getBoard()->newBlock( player2.getSnake()->getSnake().first() );
}

void c_game::addNewFood(QPair<bool, bool> player)
{
    if(player.first)
        player1.getBoard()->newFood( player1.getSnake()->getSnake().first() );
    if(player.second)
        player2.getBoard()->newFood( player2.getSnake()->getSnake().first() );
}

void c_game::addNewCoin(QPair<bool, bool> player)
{
    if(player.first)
        player1.getBoard()->newCoin( player1.getSnake()->getSnake().first() );
    if(player.second)
        player2.getBoard()->newCoin( player2.getSnake()->getSnake().first() );
}

void c_game::movePlayer(QPair<bool, bool> player)
{
    if(player.first)
        player1.move();
    if(player.second)
        player2.move();

}

void c_game::speedUpPlayer(QPair<bool, bool> player)
{
    if(speedLevel < game::maxSpeedUpLevel)
        ++speedLevel;

    int nextSpeed = game::beginningMoveTime - (game::speedUpValue * speedLevel );

    eventCtrlr->setNextMoveTime( nextSpeed );

    if(player.first)
        player1.speedUp(speedLevel);
    if(player.second)
        player2.speedUp(speedLevel);

    emit speedUpSignal(player, speedLevel);
}


void c_game::testPotentialCollision(QList<QPoint> &snake, const board::boardArray &board)
{
    game::colisionResult result = testCollision(snake, board);

    switch (result) {
    case game::NO_COLLISION: {
        return;
    }
    case game::BLOCK_COLLISION: {
        stopGame(sender());
        return;
    }
    case game::SNAKE_BODY_COLLISION: {
        stopGame(sender());
        return;
    }
    case game::FOOD_LVL_1_COLLISION: {
        dynamic_cast<c_player *>(sender())->getBoard()->clearField(snake.first());
        dynamic_cast<c_player *>(sender())->feedSnake( game::feedLvl1 );
        return;
    }
    case game::FOOD_LVL_2_COLLISION: {
        dynamic_cast<c_player *>(sender())->getBoard()->clearField(snake.first());
        dynamic_cast<c_player *>(sender())->feedSnake( game::feedLvl2 );
        return;
    }
    case game::COIN_LVL_1_COLLISION: {
        dynamic_cast<c_player *>(sender())->getBoard()->clearField(snake.first());
        dynamic_cast<c_player *>(sender())->coinsToWallet( game::prizeLvl1 );
        return;
    }
    case game::COIN_LVL_2_COLLISION: {
        dynamic_cast<c_player *>(sender())->getBoard()->clearField(snake.first());
        dynamic_cast<c_player *>(sender())->coinsToWallet( game::prizeLvl2 );
        return;
    }
    case game::COIN_LVL_3_COLLISION: {
        dynamic_cast<c_player *>(sender())->getBoard()->clearField(snake.first());
        dynamic_cast<c_player *>(sender())->coinsToWallet( game::prizeLvl3 );
        return;
    }
    case game::UNDEFINED_COLLISION: {
        return;
    }
    default: {
        return;
    }
    }
}

const c_player &c_game::getPlayer1() const
{
    return player1;
}

const c_player &c_game::getPlayer2() const
{
    return player2;
}



