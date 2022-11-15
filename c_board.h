#ifndef C_BOARD_H
#define C_BOARD_H

#include "_myData.h"

#include <QObject>

class c_board : public QObject
{
    Q_OBJECT
public:

    explicit c_board(QObject *parent = nullptr);
    const board::boardArray& getBoard();

public slots:

private:
    board::boardArray board;

private slots:

signals:
    void boardStateChanged(const c_board& board);

};

#endif // C_BOARD_H
