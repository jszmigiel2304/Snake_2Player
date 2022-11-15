#ifndef W_BOARDWIDGET_H
#define W_BOARDWIDGET_H

#include "c_board.h"
#include "_myData.h"
#include <QGridLayout>

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QColor>

class w_boardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_boardWidget(QWidget *parent = nullptr);
    ~w_boardWidget();

    void loadBoard(const board::boardArray &board);
    void loadSnake(const w_board::w_snake snake);
    QPixmap * getIcon(const board::BoardField field);

public slots:
    void refreshBoard(const board::boardArray &board);

private:
    w_board::boardPixmapsArray boardLabelsArray;
    w_board::iconMap icons;

    uint fieldWidth;
    uint fieldHeight;

    void loadIcons();

signals:

};

#endif // W_BOARDWIDGET_H
