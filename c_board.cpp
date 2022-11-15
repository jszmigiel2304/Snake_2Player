#include "c_board.h"

c_board::c_board(QObject *parent)
    : QObject{parent}
{
    for(int iii = 0; iii < board::boardSize; iii++) {
        for(int jjj = 0; jjj < board::boardSize; jjj++) {
            if (iii == 0 || jjj == 0 || iii == board::boardSize-1 || jjj == board::boardSize-1) {
                board[iii][jjj] = board::WALL;
                continue;
            } else {
                board[iii][jjj] = board::EMPTY;
                continue;
            }
        }
    }
}

const board::boardArray &c_board::getBoard()
{
    return board;
}
