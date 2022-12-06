#include "w_mainmenuinterface.h"
#include "c_interfacefactory.h"
#include "w_tpbutton.h"

w_MainMenuInterface::w_MainMenuInterface(int Gwidth, int Gheight, QWidget *parent)
    : w_UserInterface{parent}
{
    settingsButton = nullptr;
    closeButton = nullptr;
    joinButton = nullptr;
    newButton = nullptr;
    setGeometry(0,0,Gwidth, Gheight);
}

w_MainMenuInterface::~w_MainMenuInterface()
{

}

void w_MainMenuInterface::createTopBox()
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
    joinButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, getMyEventFilter());
    dynamic_cast<w_tpButton *>(joinButton)->setTextSizeCheck("JOIN");
    newButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, getMyEventFilter());
    dynamic_cast<w_tpButton *>(newButton)->setTextSizeCheck("NEW");

    connect(joinButton, SIGNAL(clicked(bool)), this, SLOT(joinButtonPressed(bool)));
    connect(newButton, SIGNAL(clicked(bool)), this, SLOT(newButtonPressed(bool)));
    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(settingsButtonPressed(bool)));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed(bool)));


    QHBoxLayout *layout = new QHBoxLayout(topBox);
    layout->setSpacing(0);
    layout->addWidget(newButton);
    layout->addWidget(joinButton);
    static_cast<QHBoxLayout *>(layout)->insertStretch(2, topBox->width()-600);
    layout->addWidget(settingsButton);
    layout->addWidget(closeButton);

    topBox->setLayout(layout);
}

void w_MainMenuInterface::createCentralBox()
{

}

void w_MainMenuInterface::createBottomBox()
{

}

void w_MainMenuInterface::joinButtonPressed(bool checked)
{
    emit joinGameButtonPressed(checked);
}

void w_MainMenuInterface::newButtonPressed(bool checked)
{
    emit newGameButtonPressed(checked);
}


void w_MainMenuInterface::settingsButtonPressed(bool checked)
{
    emit settingsGameButtonPressed(checked);
}

void w_MainMenuInterface::closeButtonPressed(bool checked)
{
    emit closeGameButtonPressed(checked);
}
