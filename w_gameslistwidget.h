#ifndef W_GAMESLISTWIDGET_H
#define W_GAMESLISTWIDGET_H

#include "_myData.h"
#include "w_gameslistitemWidget.h"
#include "c_myinterfaceeventfilter.h"

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QList>
#include <QVBoxLayout>

class w_gamesListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_gamesListWidget(int GWIdth, int GHeight, QWidget *parent = nullptr);
    ~w_gamesListWidget();

public slots:
    void loadLobbiesList(const QList<lobby::lobbyInformations> &lobbiesInfos);
    void newGeometry(int x, int y, int w, int h);

private:
    QList<lobby::lobbyInformations> lobbiesInfos;
    QList<w_gamesListItemWidget *> gamesListWidgetItems;

    QWidget *centralWidget;
    QScrollArea *gamesListScrollArea;

    const lobby::lobbyInformations &getLobbyInfo(const QString &lobbyName) const;
    void clearGamesListWidgetList();

private slots:
    void joinGameBuuttonClicked(const QString &gameName);

signals:
    void joinLobbySignal(const lobby::lobbyInformations & gameInfo);

};

#endif // W_GAMESLISTWIDGET_H
