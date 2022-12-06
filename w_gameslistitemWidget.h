#ifndef W_GAMESLISTITEMWIDGET_H
#define W_GAMESLISTITEMWIDGET_H

#include "_myData.h"
#include "c_myinterfaceeventfilter.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHBoxLayout>


class w_gamesListItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_gamesListItemWidget(int GWidth, int GHeight, QWidget *parent = nullptr);
    ~w_gamesListItemWidget();

    const QString &getLobbyName();

public slots:
    void loadGameInfo(const lobby::lobbyInformations &lobbyInfo);

private:
    lobby::lobbyInformations lobbyInfo;

    QWidget *centralWidget;
    QWidget *gameNameLabel;
    QWidget *playerOneNameLabel;
    QWidget *playerTwoNameLabel;
    QWidget *joinLobbyButton;

private slots:
    void joinLobbyButtonClicked(bool checked);

signals:
    void joinButtonClicked(QString gameName);

};

#endif // W_GAMESLISTITEMWIDGET_H
