#include "w_gameslistwidget.h"
#include "c_interfacefactory.h"
#include "w_gameslistitemWidget.h"


w_gamesListWidget::w_gamesListWidget(int GWidth, int GHeight, QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: transparent;");
    gamesListScrollArea = new QScrollArea(this);
    gamesListScrollArea->setStyleSheet("background-color: transparent;");
    centralWidget = new QWidget();
    centralWidget->setStyleSheet("background-color: rgba(255,255,255, 0.3);");

    resize(GWidth, GHeight);

    gamesListScrollArea->setGeometry(0,0,GWidth,GHeight);
    gamesListScrollArea->setWidget(centralWidget);
    gamesListScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gamesListScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    centralWidget->setLayout(new QVBoxLayout());
    dynamic_cast<QVBoxLayout *>(centralWidget->layout())->insertStretch(0);
}

w_gamesListWidget::~w_gamesListWidget()
{
    //gamesInfos.clear();

    clearGamesListWidgetList();
}

void w_gamesListWidget::loadLobbiesList(const QList<lobby::lobbyInformations> &lobbiesInfos)
{
    if(!gamesListWidgetItems.isEmpty())
        clearGamesListWidgetList();

    this->lobbiesInfos = lobbiesInfos;

    if(55*lobbiesInfos.size() < gamesListScrollArea->height())
        centralWidget->resize(width(), gamesListScrollArea->height());
    else
        centralWidget->resize(width(), 55*lobbiesInfos.size());

    int iii = 0;
    foreach (const lobby::lobbyInformations &lobbyInfo, this->lobbiesInfos) {
        QWidget * item = c_interfaceFactory::createWidget(Interface_NS::WT_GAMES_LIST_BOX_ITEM, centralWidget, parent());

        connect(dynamic_cast<w_gamesListItemWidget *>(item), SIGNAL(joinButtonClicked(QString)), this, SLOT(joinGameBuuttonClicked(QString)));
        gamesListWidgetItems.append(dynamic_cast<w_gamesListItemWidget *>(item));
        dynamic_cast<QVBoxLayout *>(centralWidget->layout())->insertWidget(0, item);
        dynamic_cast<QVBoxLayout *>(centralWidget->layout())->setStretch(iii+1, gamesListScrollArea->height() - iii*55);
        //centralWidget->layout()->addWidget(item);
        dynamic_cast<w_gamesListItemWidget *>(item)->loadGameInfo(lobbyInfo);
        ++iii;
    }
}

void w_gamesListWidget::newGeometry(int x, int y, int w, int h)
{
    setGeometry(x,y,w,h);
    gamesListScrollArea->setGeometry(0,0,w,h);
    centralWidget->setGeometry(0,0,w,h);
}

const lobby::lobbyInformations &w_gamesListWidget::getLobbyInfo(const QString &lobbyName) const
{
    auto lobbyInfo = std::find_if(lobbiesInfos.begin(), lobbiesInfos.end(),
                                     [&lobbyName](const lobby::lobbyInformations lobby) {return lobby.lobbyName == lobbyName;} );

    return *lobbyInfo;
}

void w_gamesListWidget::clearGamesListWidgetList()
{
    qDeleteAll(gamesListWidgetItems);
    gamesListWidgetItems.clear();
}

void w_gamesListWidget::joinGameBuuttonClicked(const QString &lobbyName)
{
    emit joinLobbySignal( getLobbyInfo(lobbyName) );
}
