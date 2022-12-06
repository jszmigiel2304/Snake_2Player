#include "w_newgameinterface.h"
#include "c_interfacefactory.h"
#include "w_tpbutton.h"
#include "w_lobbyboxwidget.h"
#include "w_gameslistwidget.h"

w_NewGameInterface::w_NewGameInterface(int Gwidth, int Gheight, QWidget *parent)
    : w_UserInterface{parent}
{
    settingsButton = nullptr;
    closeButton = nullptr;
    backButton = nullptr;
    lobbyBox = nullptr;
    gamesListBox = nullptr;
    setGeometry(0,0,Gwidth, Gheight);
}

w_NewGameInterface::~w_NewGameInterface()
{

}

void w_NewGameInterface::refreshLobbyBox(lobby::lobbyInformations lobbyInfo)
{
    if(lobbyBox) {
        dynamic_cast<w_lobbyBoxWidget *>(lobbyBox)->loadGameInfo(lobbyInfo);
    }
}

void w_NewGameInterface::refreshLobbiesListBox(const QList<lobby::lobbyInformations> &lobbiesInfos)
{
    if(gamesListBox) {
        dynamic_cast<w_gamesListWidget *>(gamesListBox)->loadLobbiesList(lobbiesInfos);
    }
}

void w_NewGameInterface::createTopBox()
{
    topBox = new QWidget(this);
    topBox->setStyleSheet("background-color: transparent;");
    int w = width(), h = height();
    topBox->setGeometry(w / 48,
                         h / 54,
                         w - (2 * w / 48),
                         100);
    topBox->setMinimumSize(w - (2 * (w / 48)), 100);
    topBox->setMaximumSize(w - (2 * (w / 48)), 100);

    settingsButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, getMyEventFilter());
    dynamic_cast<w_tpButton *>(settingsButton)->setTextSizeCheck("SETTINGS");
    closeButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, getMyEventFilter());
    dynamic_cast<w_tpButton *>(closeButton)->setTextSizeCheck("CLOSE");
    backButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, getMyEventFilter());
    dynamic_cast<w_tpButton *>(backButton)->setTextSizeCheck("BACK");

    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(backButtonPressed(bool)));
    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(settingsButtonPressed(bool)));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed(bool)));


    QHBoxLayout *layout = new QHBoxLayout(topBox);
    layout->setSpacing(0);
    layout->addWidget(backButton);
    static_cast<QHBoxLayout *>(layout)->insertStretch(1, topBox->width()-450);
    layout->addWidget(settingsButton);
    layout->addWidget(closeButton);

    topBox->setLayout(layout);

}

void w_NewGameInterface::createCentralBox()
{
    centralBox = new QWidget(this);
    centralBox->setStyleSheet("background-color: transparent;");
    int w = width(), h = height();
    centralBox->setGeometry(w / 48,
                         (h / 54) + 100,
                         w - (2 * w / 48),
                         h - ((h / 54) + 100));

    centralBox->setMinimumSize(w - (2 * w / 48), h - ((h / 54) + 100));
    centralBox->setMaximumSize(w - (2 * w / 48), h - ((h / 54) + 100));

    lobbyBox = c_interfaceFactory::createWidget(Interface_NS::WT_LOBBY_BOX, centralBox);
    gamesListBox = c_interfaceFactory::createWidget(Interface_NS::WT_GAMES_LIST_BOX, centralBox);
    dynamic_cast<w_gamesListWidget *>(gamesListBox)->newGeometry(0, lobbyBox->height() + (h / 54), centralBox->width(), (centralBox->height()-lobbyBox->height()) -  2 * (h / 54) );
}

void w_NewGameInterface::createBottomBox()
{

}

void w_NewGameInterface::backButtonPressed(bool checked)
{
    emit backGameButtonPressed(checked);
}

void w_NewGameInterface::settingsButtonPressed(bool checked)
{
    emit settingsGameButtonPressed(checked);
}

void w_NewGameInterface::closeButtonPressed(bool checked)
{
    emit closeGameButtonPressed(checked);
}
