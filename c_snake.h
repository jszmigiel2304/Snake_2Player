#ifndef C_SNAKE_H
#define C_SNAKE_H

#include "_myData.h"

#include <QObject>
#include <QPoint>
#include <QList>

class c_snake : public QObject
{
    Q_OBJECT

public:
    explicit c_snake(QObject *parent = nullptr);

    const QList<QPoint> &getSnake() const;

    snake::MoveDirection getDirection() const;

signals:

private:
    QList<QPoint> snake;
    snake::MoveDirection direction;

};

#endif // C_SNAKE_H
