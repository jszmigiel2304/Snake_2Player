#include "w_boardwidget.h"

w_boardWidget::w_boardWidget(QWidget *parent)
    : QWidget{parent}
{
    setIcons( dynamic_cast<c_MyQApplication *>(qApp)->getIcons() );
}

w_boardWidget::~w_boardWidget()
{
    for(int iii = 0; iii < board::boardSize; iii++) {
        for(int jjj = 0; jjj < board::boardSize; jjj++) {
            delete boardLabelsArray[iii][jjj];
        }
    }

}

void w_boardWidget::refreshBoard(const board::boardArray &board)
{
    for(int iii = 1; iii < board::boardSize - 1; iii++) {
        for(int jjj = 1; jjj < board::boardSize - 1; jjj++) {
            if( board[iii][jjj] >= 3 && board[iii][jjj] < 50 ) {
                continue;
            }

            if(!(*(*icons)[board[iii][jjj]]).isNull())
                boardLabelsArray[iii][jjj]->setPixmap( (*(*icons)[board[iii][jjj]]).scaled(fieldWidth, fieldWidth) );
        }
    }
}

void w_boardWidget::refreshSnake(const w_board::w_snake &snake)
{
    loadSnake(snake);
}

w_board::iconMap w_boardWidget::getIcons() const
{
    return icons;
}

void w_boardWidget::setIcons(w_board::iconMap newIcons)
{
    icons = newIcons;
}

void w_boardWidget::loadBoard(const board::boardArray &board)
{
    int min = width() < height() ? width() : height();

    fieldWidth = min / board::boardSize;
    fieldHeight = min / board::boardSize;

    int marginLeft = width() - min;
    int marginTop = height() - min;

    for(int iii = 0; iii < board::boardSize; iii++) {
        for(int jjj = 0; jjj < board::boardSize; jjj++) {
            QLabel *boardFieldLabel = new QLabel(this);
            boardFieldLabel->setGeometry((iii * fieldWidth) + (marginLeft / 2),
                                         (jjj * fieldHeight) + (marginTop / 2),
                                         fieldWidth,
                                         fieldHeight);


            if(jjj == 0 ||  jjj == board::boardSize-1)
                boardFieldLabel->setObjectName("boardWallTopBottomLabel");
            else if(iii == 0 || iii == board::boardSize-1)
                boardFieldLabel->setObjectName("boardWallLeftRightLabel");
            else
                boardFieldLabel->setObjectName("boardFieldLabel");

            if(!(*(*icons)[board[iii][jjj]]).isNull())
                boardFieldLabel->setPixmap( (*(*icons)[board[iii][jjj]]).scaled(fieldWidth, fieldWidth) );

            boardFieldLabel->setAlignment(Qt::AlignCenter);
            boardLabelsArray[iii][jjj] = boardFieldLabel;
        }
    }
    boardLabelsArray[0][0]->setObjectName("boardLeftTopCornerLabel");
    boardLabelsArray[0][board::boardSize-1]->setObjectName("boardLeftBottomCornerLabel");
    boardLabelsArray[board::boardSize-1][0]->setObjectName("boardRightTopCornerLabel");
    boardLabelsArray[board::boardSize-1][board::boardSize-1]->setObjectName("boardRightBottomCornerLabel");

}

void w_boardWidget::loadSnake(const w_board::w_snake snake)
{
    for(int iii=0; iii<snake.size(); iii++) {
        boardLabelsArray[ snake[iii].x ][ snake[iii].y ]->setPixmap( (*snake[iii].pixmap).scaled(fieldWidth, fieldWidth) );
    }
}

QPixmap *w_boardWidget::getIcon(const board::BoardField field)
{
    return (*icons)[field];
}
