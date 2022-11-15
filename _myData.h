#ifndef _MYDATA_H
#define _MYDATA_H

#include <QObject>
#include <QPixmap>
#include <QMap>
#include <QLabel>
#include <QList>
#include <QPoint>

namespace board {
    const quint8 boardSize = 50;

    enum BoardField : quint8 {
        EMPTY,
        WALL,
        BLOCK,
        SNAKE_HEAD_DOWN,
        SNAKE_HEAD_UP,
        SNAKE_HEAD_LEFT,
        SNAKE_HEAD_RIGHT,
        SNAKE_BODY_HORIZONTAL,
        SNAKE_BODY_VERTICAL,
        SNAKE_BODY_BEND_LT,
        SNAKE_BODY_BEND_LB,
        SNAKE_BODY_BEND_RT,
        SNAKE_BODY_BEND_RB,
        SNAKE_TAIL_DOWN,
        SNAKE_TAIL_UP,
        SNAKE_TAIL_LEFT,
        SNAKE_TAIL_RIGHT,
        FOOD_LVL_1,
        FOOD_LVL_2,
        COIN_LVL_1,
        COIN_LVL_2,
        COIN_LVL_3,
    };

    typedef BoardField boardArray[board::boardSize][board::boardSize];

} // namespace board

namespace w_board {

    struct w_snakePart
    {
        int x;
        int y;
        QPixmap * pixmap;
    };

    typedef QLabel * boardPixmapsArray[board::boardSize][board::boardSize];
    typedef QMap<board::BoardField, QPixmap *> iconMap;
    typedef QList<w_snakePart> w_snake;
}

namespace snake {

    enum MoveDirection : quint8 {
        MOVE_UP,
        MOVE_RIGHT,
        MOVE_DOWN,
        MOVE_LEFT
    };

    struct snake {
        QList<QPoint> snake;
        MoveDirection direction;
    };

}

#endif // _MYDATA_H
