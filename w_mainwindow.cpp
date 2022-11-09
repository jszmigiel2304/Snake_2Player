#include "w_mainwindow.h"

w_MainWindow::w_MainWindow(QList<QPair<QString, QVariant>> settings, QWidget *parent)
    : QMainWindow(parent)
{
    myEventFilter = new c_myInterfaceEventFilter(this);

    setWindowTitle( qApp->applicationDisplayName() );

    central = new QWidget();
    topBox = new QWidget();
    gameBox = new QWidget();
    player1GameBox = new QWidget();
    player2GameBox = new QWidget();

    startButton = new QPushButton();
    settingButton = new QPushButton();
    closeButton = new QPushButton();
    joinButton = new QPushButton();
    newButton = new QPushButton();

    player1NotifyLabel =  new QLabel();
    player2NotifyLabel =  new QLabel();

    sppedUpCounterPlayer1 = new w_speedUpCounterWidget();
    sppedUpCounterPlayer2 = new w_speedUpCounterWidget();

    coinsWidgetPlayer1 = new w_coinsWidget();
    coinsWidgetPlayer2 = new w_coinsWidget();

    shopPlayer1 = new w_shopWidget();
    shopPlayer2 = new w_shopWidget();

    boardPlayer1 = new QWidget();
    boardPlayer2 = new QWidget();

    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(startButtonPressed()));
    connect(settingButton, SIGNAL(clicked(bool)), this, SLOT(settingsButtonPressed()));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed()));
    connect(joinButton, SIGNAL(clicked(bool)), this, SLOT(joinButtonPressed()));
    connect(newButton, SIGNAL(clicked(bool)), this, SLOT(newButtonPressed()));

    startButton->installEventFilter(myEventFilter);
    settingButton->installEventFilter(myEventFilter);
    closeButton->installEventFilter(myEventFilter);
    joinButton->installEventFilter(myEventFilter);
    newButton->installEventFilter(myEventFilter);

    central->setObjectName("centralWidget");
    topBox->setObjectName("topBoxWidget");
    gameBox->setObjectName("gameBoxWidget");
    player1GameBox->setObjectName("player1GameBoxWidget");
    player2GameBox->setObjectName("player2GameBoxWidget");
    startButton->setObjectName("startButtonWidget");
    settingButton->setObjectName("settingButtonWidget");
    closeButton->setObjectName("closeButtonWidget");
    joinButton->setObjectName("joinButtonWidget");
    newButton->setObjectName("newButtonWidget");
    player1NotifyLabel->setObjectName("player1NotifyLabel");
    player2NotifyLabel->setObjectName("player2NotifyLabel");
    player1NotifyLabel->setText("[ player1NotifyLabel ]");
    player2NotifyLabel->setText("[ player2NotifyLabel ]");
    boardPlayer1->setObjectName("boardPlayer1Widget");
    boardPlayer2->setObjectName("boardPlayer2Widget");

    QMetaObject::connectSlotsByName(this);

    for(int i=0; i<settings.size(); i++) {
        if( settings[i].first == "fullscreen_mode" ) setGfullscreen_mode( settings[i].second.toBool() );
        if( settings[i].first == "width" ) setGwidth( settings[i].second.toInt() );
        if( settings[i].first == "height" ) setGheight( settings[i].second.toInt() );
    }

    if(getGfullscreen_mode())
        setWindowState(Qt::WindowFullScreen);

    setMinimumHeight(getGheight());
    setMaximumHeight(getGheight());
    setMinimumWidth(getGwidth());
    setMaximumWidth(getGwidth());
    resize(getGwidth(), getGheight());

    central->setMinimumHeight(getGheight());
    central->setMaximumHeight(getGheight());
    central->setMinimumWidth(getGwidth());
    central->setMaximumWidth(getGwidth());
    central->resize(getGwidth(), getGheight());

    topBox->setGeometry(getGwidth() / 48,
                         getGheight() / 54,
                         getGwidth() - (2 * (getGwidth() / 48)),
                         90);
    gameBox->setGeometry(getGwidth() / 48,
                         (2 * (getGheight() / 54)) + 90,
                         getGwidth() - (2 * (getGwidth() / 48)),
                         getGheight() - 90 - (3 * (getGheight() / 54)));


    topBox->setParent(central);
    gameBox->setParent(central);
    player1GameBox->setParent(gameBox);
    player2GameBox->setParent(gameBox);

    player1GameBox->setGeometry(0,
                                0,
                                (gameBox->width() / 2) - 20,
                                gameBox->height()
                                );
    player2GameBox->setGeometry((gameBox->width() / 2) + 20,
                                0,
                                (gameBox->width() / 2) - 20,
                                gameBox->height()
                                );

    newButton->setGeometry(0, 0, 150, 90);
    newButton->setFlat(true);
    joinButton->setGeometry(150, 0, 150, 90);
    joinButton->setFlat(true);
    startButton->setGeometry(topBox->width() / 2 - 75, 0, 150, 90);
    startButton->setFlat(true);
    settingButton->setGeometry(topBox->width() - 300, 0, 150, 90);
    settingButton->setFlat(true);
    closeButton->setGeometry(topBox->width() - 150, 0, 150, 90);
    closeButton->setFlat(true);

    player1NotifyLabel->setGeometry(0,0, player1GameBox->width(), 90);
    player1NotifyLabel->setAlignment(Qt::AlignCenter);
    player2NotifyLabel->setGeometry(0,0, player2GameBox->width(), 90);
    player2NotifyLabel->setAlignment(Qt::AlignCenter);

    sppedUpCounterPlayer1->setGeometry(player1GameBox->width() - 100,
                                player1GameBox->height() - 40,
                                100,
                                40);

    sppedUpCounterPlayer2->setGeometry(0,
                                       player2GameBox->height() - 40,
                                       100,
                                       40);


    coinsWidgetPlayer1->setGeometry(0,
                                player1GameBox->height() - 40,
                                100,
                                40);

    coinsWidgetPlayer2->setGeometry(player2GameBox->width() - 100,
                                  player2GameBox->height() - 40,
                                  100,
                                  40);

    shopPlayer1->setGeometry(player1GameBox->width() / 2 - 150,
                             player1GameBox->height() - 40,
                             300,
                             40);
    shopPlayer2->setGeometry(player2GameBox->width() / 2 - 150,
                             player2GameBox->height() - 40,
                             300,
                             40);

    boardPlayer1->setGeometry(0,
                              90,
                              player1GameBox->width(),
                              player1GameBox->height() - 150);
    boardPlayer2->setGeometry(0,
                              90,
                              player2GameBox->width(),
                              player2GameBox->height() - 150);

    startButton->setParent(topBox);
    settingButton->setParent(topBox);
    closeButton->setParent(topBox);
    newButton->setParent(topBox);
    joinButton->setParent(topBox);

    player1NotifyLabel->setParent(player1GameBox);
    player2NotifyLabel->setParent(player2GameBox);

    sppedUpCounterPlayer1->setParent(player1GameBox);
    sppedUpCounterPlayer2->setParent(player2GameBox);

    coinsWidgetPlayer1->setParent(player1GameBox);
    coinsWidgetPlayer2->setParent(player2GameBox);

    shopPlayer1->setParent(player1GameBox);
    shopPlayer2->setParent(player2GameBox);

    boardPlayer1->setParent(player1GameBox);
    boardPlayer2->setParent(player2GameBox);

    connect(this, SIGNAL(destroyed()), topBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player1GameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player2GameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), gameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), central, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), startButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), settingButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), closeButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), newButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), joinButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player1NotifyLabel, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player2NotifyLabel, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), myEventFilter, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), sppedUpCounterPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), sppedUpCounterPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), shopPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), shopPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), boardPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), boardPlayer2, SLOT(deleteLater()));

    setCentralWidget(central);
}

w_MainWindow::~w_MainWindow()
{
}

void w_MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void w_MainWindow::joinButtonPressed()
{
    QMessageBox msgBox;
    msgBox.setText("Join button pressed.");
    msgBox.exec();
}

void w_MainWindow::newButtonPressed()
{
    QMessageBox msgBox;
    msgBox.setText("New button pressed.");
    msgBox.exec();
}

void w_MainWindow::startButtonPressed()
{
    QMessageBox msgBox;
    msgBox.setText("Start button pressed.");
    msgBox.exec();
}

void w_MainWindow::settingsButtonPressed()
{
    QMessageBox msgBox;
    msgBox.setText("Settings button pressed.");
    msgBox.exec();
}

void w_MainWindow::closeButtonPressed()
{
    close();
}

bool w_MainWindow::getGfullscreen_mode() const
{
    return gfullscreen_mode;
}

void w_MainWindow::setGfullscreen_mode(bool newGfullscreen_mode)
{
    gfullscreen_mode = newGfullscreen_mode;
}

int w_MainWindow::getGheight() const
{
    return gheight;
}

void w_MainWindow::setGheight(int newGheight)
{
    gheight = newGheight;
}

int w_MainWindow::getGwidth() const
{
    return gwidth;
}

void w_MainWindow::setGwidth(int newGwidth)
{
    gwidth = newGwidth;
}




