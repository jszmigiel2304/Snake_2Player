#ifndef C_GAME_H
#define C_GAME_H

#include "_myData.h"
#include "c_board.h"
#include "c_snake.h"

#include <QObject>
#include <QList>
#include <QPoint>

class c_game : public QObject
{
    Q_OBJECT
public:
    explicit c_game(QObject *parent = nullptr);
    ~c_game();


    c_board *getBoardPlayer1() const;
    c_board *getBoardPlayer2() const;
    c_snake *getSnakePlayer1() const;
    c_snake *getSnakePlayer2() const;

signals:

private:
    c_board * boardPlayer1;
    c_board * boardPlayer2;

    c_snake * snakePlayer1;
    c_snake * snakePlayer2;

};

#endif // C_GAME_H
