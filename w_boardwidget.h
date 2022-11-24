#ifndef W_BOARDWIDGET_H
#define W_BOARDWIDGET_H

#include "c_myqapplication.h"
#include "_myData.h"

#include <QGridLayout>
#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QColor>
#include <qapplication.h>

class w_boardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_boardWidget(QWidget *parent = nullptr);
    ~w_boardWidget();

    void loadBoard(const board::boardArray &board);
    void loadSnake(const w_board::w_snake snake);
    QPixmap * getIcon(const board::BoardField field);

    w_board::iconMap getIcons() const;
    void setIcons(w_board::iconMap newIcons);

public slots:
    void refreshBoard(const board::boardArray &board);
    void refreshSnake(const w_board::w_snake &snake);

private:
    w_board::boardPixmapsArray boardLabelsArray;
    w_board::iconMap icons;

    uint fieldWidth;
    uint fieldHeight;    


signals:

};

#endif // W_BOARDWIDGET_H
