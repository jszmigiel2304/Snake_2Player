#include "w_gameslistitemWidget.h"
#include "c_interfacefactory.h"
#include "w_gllabel.h"
#include "w_gljoinbutton.h"


w_gamesListItemWidget::w_gamesListItemWidget(int GWidth, int GHeight, QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color: transparent;"
                  "border-color: rgba(128,128,128,1);"
                  "border-style: solid;"
                  "border-top-width: 2px;"
                  "border-left-width: 2px;"
                  "border-right-width: 2px;"
                  "border-bottom-width: 3px;"
                  "color: rgba(128,128,128,1);"
                  "font: 15pt;");
    //centralWidget = new QWidget(this);
    gameNameLabel = c_interfaceFactory::createWidget(Interface_NS::WT_GLW_LABEL, this, parent);
    playerOneNameLabel = c_interfaceFactory::createWidget(Interface_NS::WT_GLW_LABEL, this, parent);
    playerTwoNameLabel = c_interfaceFactory::createWidget(Interface_NS::WT_GLW_LABEL, this, parent);
    joinLobbyButton = c_interfaceFactory::createWidget(Interface_NS::WT_GLW_BUTTON, this, parent);

    resize(GWidth, GHeight);
    setGeometry(0,0,GWidth,GHeight);
    setMinimumHeight(50);
    setMaximumHeight(50);

    dynamic_cast<QLabel *>(gameNameLabel)->setText("[ game name ]");
    dynamic_cast<QLabel *>(playerOneNameLabel)->setText("[ player_one_name ]");
    dynamic_cast<QLabel *>(playerTwoNameLabel)->setText("[ player_two_name ]");
    dynamic_cast<QPushButton *>(joinLobbyButton)->setText("JOIN");

    gameNameLabel->setGeometry(100,0,300,50);
    playerOneNameLabel->setGeometry(400,0,150,50);
    playerTwoNameLabel->setGeometry(550,0,150,50);
    joinLobbyButton->setGeometry(0,0,100,50);

    connect(joinLobbyButton, SIGNAL(clicked(bool)), this, SLOT(joinLobbyButtonClicked(bool)));
}

w_gamesListItemWidget::~w_gamesListItemWidget()
{

}

const QString &w_gamesListItemWidget::getLobbyName()
{
    return lobbyInfo.lobbyName;
}

void w_gamesListItemWidget::loadGameInfo(const lobby::lobbyInformations &lobbyInfo)
{
    this->lobbyInfo = lobbyInfo;

    if(lobbyInfo.lobbyName.size() > 30)
        dynamic_cast<QLabel *>(gameNameLabel)->setText(QString("%1...").arg(lobbyInfo.lobbyName.first(30)));
    else
        dynamic_cast<QLabel *>(gameNameLabel)->setText(lobbyInfo.lobbyName);

    if(lobbyInfo.playersNames.first.size() > 20)
        dynamic_cast<QLabel *>(playerOneNameLabel)->setText(QString("%1...").arg(lobbyInfo.playersNames.first.first(20)));
    else
        dynamic_cast<QLabel *>(playerOneNameLabel)->setText(lobbyInfo.playersNames.first);

    if(lobbyInfo.playersNames.second.size() > 20)
        dynamic_cast<QLabel *>(playerTwoNameLabel)->setText(QString("%1...").arg(lobbyInfo.playersNames.second.first(20)));
    else
        dynamic_cast<QLabel *>(playerTwoNameLabel)->setText(lobbyInfo.playersNames.second);

    if(lobbyInfo.playersNames.first.isEmpty() || lobbyInfo.playersNames.second.isEmpty())
    {
        joinLobbyButton->setEnabled(true);
        joinLobbyButton->show();
    }
    else
    {
        joinLobbyButton->setEnabled(false);
        joinLobbyButton->hide();
    }
}

void w_gamesListItemWidget::joinLobbyButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    emit joinButtonClicked(getLobbyName());

}
