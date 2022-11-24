#ifndef C_PLAYER_H
#define C_PLAYER_H

#include "_myData.h"

#include <QObject>
#include <QList>
#include <QPoint>
#include <QUuid>


class c_player : public QObject
{
    Q_OBJECT
public:
    explicit c_player(QObject *parent = nullptr);
    ~c_player();


//    c_board *getBoard() const;
//    void setBoard(c_board *newBoard);

//    c_snake *getSnake() const;
//    void setSnake(c_snake *newSnake);

//    snake::MoveDirection getNextMoveDirection() const;
//    void setNextMoveDirection(snake::MoveDirection newNextMoveDirection);

//    const c_myTimer &getSpeedUpTimer() const;

//    int getNextSpeedUpTime() const;
//    void setNextSpeedUpTime(int newNextSpeedUpTime);
//    int getNextMoveTime() const;
//    void setNextMoveTime(int newNextMoveTime);

//    c_wallet *getWallet() const;

    const QString &getName() const;

    void setName(const QString &newName);

public slots:
//    void move();
//    void speedUp(quint8 speedLevel);
//    void feedSnake(quint8 foodAmount);
//    void coinsToWallet(quint32 coins);
//    void takeCoinsFromWallet(quint32 coins);

private:
    QString name;
//    c_wallet * wallet;
//    c_board * board;
//    c_snake * snake;
//    snake::MoveDirection nextMoveDirection;

//    QTimer movingTimer;
//    c_myTimer speedUpTimer{game::speedUpNormalTime};

//    int nextSpeedUpTime;
//    int nextMoveTime;
//    quint8 speedUpLevel;

private slots:
//    void boardChanged();
//    void snakeChanged();
//    void movingTimerTimeOut();

signals:
//    void boardChangedSignal(const board::boardArray &board, const c_snake &snake);
//    void potentialCollisionSignal(QList<QPoint> & snake, const board::boardArray & board);

};

#endif // C_PLAYER_H
