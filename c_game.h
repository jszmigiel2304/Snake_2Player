#ifndef C_GAME_H
#define C_GAME_H

#include "_myData.h"
#include "c_player.h"

#include <QObject>
#include <QList>
#include <QPoint>
#include <QSet>
#include <QTimer>
#include <QPair>

class c_game : public QObject
{
    Q_OBJECT
public:
    explicit c_game(QObject *parent = nullptr);
    ~c_game();

    const c_player &getPlayer1() const;
    const c_player &getPlayer2() const;

//    c_eventController *getEventCtrlr() const;

public slots:
//    void changeMoveDirection(QList<int> keys);

private:
    game::Players players;
//    c_player player1;
//    c_player player2;

//    quint8 speedLevel;

//    c_eventController * eventCtrlr;

//    game::ColisionResult testCollision(QList<QPoint> &snake, const board::boardArray & board);

//    void stopGame(QObject * loserPlayer);

private slots:
//    void addNewBlock(QPair<bool, bool> player);
//    void addNewFood(QPair<bool, bool> player);
//    void addNewCoin(QPair<bool, bool> player);
//    void movePlayer(QPair<bool, bool> player);
//    void speedUpPlayer(QPair<bool, bool> player);
//    void testPotentialCollision(QList<QPoint> & snake, const board::boardArray & board);

signals:
//    void speedUpSignal(QPair<bool, bool> player, quint8 speedLevel);
    void notificationMessage(QPair<bool, bool> player, QString msg);
//    void stopGameSignal();

};

#endif // C_GAME_H
