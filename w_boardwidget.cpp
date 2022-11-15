#include "w_boardwidget.h"

w_boardWidget::w_boardWidget(QWidget *parent)
    : QWidget{parent}
{    
    loadIcons();
}

w_boardWidget::~w_boardWidget()
{
    qDeleteAll(icons.begin(), icons.end());
    icons.clear();

    for(int iii = 0; iii < board::boardSize; iii++) {
        for(int jjj = 0; jjj < board::boardSize; jjj++) {
            delete boardLabelsArray[iii][jjj];
        }
    }

}

void w_boardWidget::refreshBoard(const board::boardArray &board)
{

}

void w_boardWidget::loadIcons()
{
    QPixmap * pixmap = new QPixmap(":/graphs/board_empty50x50.png", "png");
    if( !pixmap->isNull() )
        icons[board::EMPTY] = new QPixmap();
    else
        icons[board::EMPTY] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/wall_50x50.png", "png");
    if( !pixmap->isNull() )
        icons[board::WALL] = new QPixmap(*pixmap);
    else
        icons[board::WALL] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/wall_50x50.png", "png");
    if( !pixmap->isNull() )
        icons[board::WALL] = new QPixmap(*pixmap);
    else
        icons[board::WALL] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/block_50x50.png", "png");
    if( !pixmap->isNull() )
        icons[board::BLOCK] = new QPixmap(*pixmap);
    else
        icons[board::BLOCK] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_head_50x50.png", "png");
    if( !pixmap->isNull() ) {
        icons[board::SNAKE_HEAD_DOWN] = new QPixmap(*pixmap);
        icons[board::SNAKE_HEAD_UP] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
        icons[board::SNAKE_HEAD_LEFT] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
        icons[board::SNAKE_HEAD_RIGHT] = new QPixmap((*pixmap).transformed(QTransform().rotate(-90)));
    }
    else {
        icons[board::SNAKE_HEAD_DOWN] = new QPixmap();
        icons[board::SNAKE_HEAD_UP] = new QPixmap();
        icons[board::SNAKE_HEAD_LEFT] = new QPixmap();
        icons[board::SNAKE_HEAD_RIGHT] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_50x50.png", "png");
    if( !pixmap->isNull() ) {
        icons[board::SNAKE_BODY_HORIZONTAL] = new QPixmap(*pixmap);
        icons[board::SNAKE_BODY_VERTICAL] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
    } else {
        icons[board::SNAKE_BODY_HORIZONTAL] = new QPixmap();
        icons[board::SNAKE_BODY_VERTICAL] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_bend_50x50.png", "png");
    if( !pixmap->isNull() ) {
        icons[board::SNAKE_BODY_BEND_LT] = new QPixmap(*pixmap);
        icons[board::SNAKE_BODY_BEND_RB] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
    } else {
        icons[board::SNAKE_BODY_BEND_LT] = new QPixmap();
        icons[board::SNAKE_BODY_BEND_RB] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_bend_2_50x50.png", "png");
    if( !pixmap->isNull() ) {
        icons[board::SNAKE_BODY_BEND_LB] = new QPixmap(*pixmap);
        icons[board::SNAKE_BODY_BEND_RT] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
    } else {
        icons[board::SNAKE_BODY_BEND_LB] = new QPixmap();
        icons[board::SNAKE_BODY_BEND_RT] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_tail_50x50.png", "png");
    if( !pixmap->isNull() ) {
        icons[board::SNAKE_TAIL_RIGHT] = new QPixmap(*pixmap);
        icons[board::SNAKE_TAIL_LEFT] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
        icons[board::SNAKE_TAIL_DOWN] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
        icons[board::SNAKE_TAIL_UP] = new QPixmap((*pixmap).transformed(QTransform().rotate(-90)));
    } else {
        icons[board::SNAKE_TAIL_UP] = new QPixmap();
        icons[board::SNAKE_TAIL_DOWN] = new QPixmap();
        icons[board::SNAKE_TAIL_LEFT] = new QPixmap();
        icons[board::SNAKE_TAIL_RIGHT] = new QPixmap();
    }
    delete pixmap;
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

            if(!(*icons[board[iii][jjj]]).isNull())
                boardFieldLabel->setPixmap( (*icons[board[iii][jjj]]).scaled(fieldWidth, fieldWidth) );

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
    return icons[field];
}


//    EMPTY,
//    WALL,
//    BLOCK,
//    SNAKE_HEAD,
//    SNAKE_BODY,
//    SNAKE_TAIL,
//    FOOD_LVL_1,
//    FOOD_LVL_2,
//    COIN_LVL_1,
//    COIN_LVL_2,
//    COIN_LVL_3,
