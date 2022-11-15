#include "c_snake.h"

c_snake::c_snake(QObject *parent)
    : QObject{parent}
{
    direction = snake::MOVE_UP;
    snake.append(QPoint(20,20));
    snake.append(QPoint(20,21));
    snake.append(QPoint(20,22));
    snake.append(QPoint(21,22));
    snake.append(QPoint(21,23));
    snake.append(QPoint(22,23));
    snake.append(QPoint(23,23));
    snake.append(QPoint(24,23));
    snake.append(QPoint(25,23));
    snake.append(QPoint(25,22));
}

const QList<QPoint> &c_snake::getSnake() const
{
    return snake;
}

snake::MoveDirection c_snake::getDirection() const
{
    return direction;
}

