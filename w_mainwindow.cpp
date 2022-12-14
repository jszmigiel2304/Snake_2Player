#include "w_mainwindow.h"
#include "c_interfacefactory.h"
#include "w_mainmenuinterface.h"
#include "w_newgameinterface.h"

w_MainWindow::w_MainWindow(QList<QPair<QString, QVariant>> settings, QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle( qApp->applicationDisplayName() );

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

    this->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                             "stop:0 rgba(9,9,121,1), stop: 0.1 rgba(0,212,255,1),"
                             "stop:0.1 rgba(0,212,255,1), stop: 0.5 rgba(0,255,179,1),"
                             "stop:0.5 rgba(0,255,179,1), stop: 0.9 rgba(0,212,255,1),"
                             "stop:0.9 rgba(0,212,255,1), stop: 1 rgba(9,9,121,1),"
                             "stop:1 rgba(9,9,121,1));");

    createMainMenuInterface();
}

w_MainWindow::~w_MainWindow()
{
}

void w_MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void w_MainWindow::createMainMenuInterface()
{
    if(central)
        delete central.data();

    central = c_interfaceFactory::createUserInterface(Interface_NS::IT_MAIN_MENU, this);
    dynamic_cast<w_MainMenuInterface *>(central.data())->createInterface();
    setCentralWidget(central);

    connect(centralWidget(), SIGNAL(newGameButtonPressed(bool)), this, SLOT(newButtonPressed()));
    connect(centralWidget(), SIGNAL(joinGameButtonPressed(bool)), this, SLOT(joinButtonPressed()));
    connect(centralWidget(), SIGNAL(settingsGameButtonPressed(bool)), this, SLOT(settingsButtonPressed()));
    connect(centralWidget(), SIGNAL(closeGameButtonPressed(bool)), this, SLOT(closeButtonPressed()));
}

void w_MainWindow::createNewGameInterface()
{
    if(central)
        delete central.data();

    central = c_interfaceFactory::createUserInterface(Interface_NS::IT_NEW_GAME, this);
    dynamic_cast<w_NewGameInterface *>(central.data())->createInterface();
    setCentralWidget(central);

    connect(this, SIGNAL(refreshLobbyBoxSignal(lobby::lobbyInformations)), dynamic_cast<w_NewGameInterface *>(central.data()), SLOT(refreshLobbyBox(lobby::lobbyInformations)));
    connect(this, SIGNAL(refreshLobbiesListBoxSignal(const QList<lobby::lobbyInformations> &)), dynamic_cast<w_NewGameInterface *>(central.data()), SLOT(refreshLobbiesListBox(const QList<lobby::lobbyInformations> &)));

    connect(centralWidget(), SIGNAL(backGameButtonPressed(bool)), this, SLOT(backButtonPressed()));
    connect(centralWidget(), SIGNAL(settingsGameButtonPressed(bool)), this, SLOT(settingsButtonPressed()));
    connect(centralWidget(), SIGNAL(closeGameButtonPressed(bool)), this, SLOT(closeButtonPressed()));
}

//w_boardWidget *w_MainWindow::getBoardPlayer1() const
//{
//    return boardPlayer1;
//}

//void w_MainWindow::setBoardPlayer1(w_boardWidget *newBoardPlayer1)
//{
//    boardPlayer1 = newBoardPlayer1;
//}

//w_boardWidget *w_MainWindow::getBoardPlayer2() const
//{
//    return boardPlayer2;
//}

//void w_MainWindow::setBoardPlayer2(w_boardWidget *newBoardPlayer2)
//{
//    boardPlayer2 = newBoardPlayer2;
//}

//const w_board::w_snake &w_MainWindow::getSnakePlayer1() const
//{
//    return snakePlayer1;
//}

//void w_MainWindow::setSnakePlayer1(const w_board::w_snake &newSnakePlayer1)
//{
//    snakePlayer1 = newSnakePlayer1;
//}

//const w_board::w_snake &w_MainWindow::getSnakePlayer2() const
//{
//    return snakePlayer2;
//}

//void w_MainWindow::setSnakePlayer2(const w_board::w_snake &newSnakePlayer2)
//{
//    snakePlayer2 = newSnakePlayer2;
//}

//void w_MainWindow::stopRefreshing()
//{
//    refreshBoardStatus = false;
//}

//void w_MainWindow::createInterface()
//{
//    central = c_interfaceFactory::createUserInterface(Interface_NS::IT_MAIN_MENU, this);
//    //central = new QWidget();
//    //topBox = new QWidget();
//    //gameBox = new QWidget();

//    //central->setObjectName("centralWidget");
//    //topBox->setObjectName("topBoxWidget");
//    //gameBox->setObjectName("gameBoxWidget");

////    gameBox->setGeometry(getGwidth() / 48,
////                         (2 * (getGheight() / 54)) + 90,
////                         getGwidth() - (2 * (getGwidth() / 48)),
////                         getGheight() - 90 - (3 * (getGheight() / 54)));

////    gameBox->setParent(central);


//    //createTopPanel();
//    //createLobbyBoxWidget();
//    //createGamesListBoxWidget();
////    createPlayer1GmaeBox();
////    createPlayer2GmaeBox();

////    connect(this, SIGNAL(destroyed()), gameBox, SLOT(deleteLater()));
////    connect(this, SIGNAL(destroyed()), central, SLOT(deleteLater()));

//    setCentralWidget(central);
//}

//void w_MainWindow::createTopPanel()
//{
//    topBox->setGeometry(getGwidth() / 48,
//                         getGheight() / 54,
//                         getGwidth() - (2 * (getGwidth() / 48)),
//                         90);
//    topBox->setParent(central);

//    startButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);
//    settingButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);
//    closeButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);
//    joinButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);
//    newButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);
    //backButton = c_interfaceFactory::createWidget(Interface_NS::WT_TP_BUTTON, topBox, myEventFilter);

//    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(startButtonPressed()));
//    connect(settingButton, SIGNAL(clicked(bool)), this, SLOT(settingsButtonPressed()));
//    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonPressed()));
//    connect(joinButton, SIGNAL(clicked(bool)), this, SLOT(joinButtonPressed()));
//    connect(newButton, SIGNAL(clicked(bool)), this, SLOT(newButtonPressed()));
    //connect(backButton, SIGNAL(clicked(bool)), this, SLOT(backButtonPressed()));

    //startButton->installEventFilter(myEventFilter);
//    settingButton->installEventFilter(myEventFilter);
//    closeButton->installEventFilter(myEventFilter);
//    joinButton->installEventFilter(myEventFilter);
//    newButton->installEventFilter(myEventFilter);
//    backButton->installEventFilter(myEventFilter);

    //startButton->setObjectName("startButtonWidget");
//    settingButton->setObjectName("settingButtonWidget");
//    closeButton->setObjectName("closeButtonWidget");
//    joinButton->setObjectName("joinButtonWidget");
//    newButton->setObjectName("newButtonWidget");
//    backButton->setObjectName("backButtonWidget");



//    newButton->setGeometry(0, 0, 150, 90);
//    //ewButton->setFlat(true);
//    joinButton->setGeometry(150, 0, 150, 90);
//    //joinButton->setFlat(true);
//    startButton->setGeometry(topBox->width() / 2 - 75, 0, 150, 90);
//    //startButton->setFlat(true);
//    settingButton->setGeometry(topBox->width() - 300, 0, 150, 90);
//    //settingButton->setFlat(true);
//    closeButton->setGeometry(topBox->width() - 150, 0, 150, 90);
//    //closeButton->setFlat(true);
//    //backButton->setGeometry(0, 0, 150, 90);
//    //backButton->setFlat(true);

    //startButton->setParent(topBox);
//    settingButton->setParent(topBox);
//    closeButton->setParent(topBox);
//    newButton->setParent(topBox);
//    joinButton->setParent(topBox);
//    backButton->setParent(topBox);

//    connect(this, SIGNAL(destroyed()), topBox, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), startButton, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), settingButton, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), closeButton, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), newButton, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), joinButton, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), backButton, SLOT(deleteLater()));

    //startButton->setFocusPolicy(Qt::NoFocus);
//    settingButton->setFocusPolicy(Qt::NoFocus);
//    closeButton->setFocusPolicy(Qt::NoFocus);
//    joinButton->setFocusPolicy(Qt::NoFocus);
//    newButton->setFocusPolicy(Qt::NoFocus);
//    backButton->setFocusPolicy(Qt::NoFocus);

//    backButton->hide();
//}

//void w_MainWindow::createPlayer1GmaeBox()
//{
//    player1GameBox = new QWidget();
//    player1NotifyLabel =  new QLabel();
//    speedUpCounterPlayer1 = new w_speedUpCounterWidget();
//    coinsWidgetPlayer1 = new w_coinsWidget();
//    shopPlayer1 = new w_shopWidget();
//    boardPlayer1 = new w_boardWidget();
//    player1GameBox->setObjectName("player1GameBoxWidget");
//    player1NotifyLabel->setObjectName("player1NotifyLabel");
//    player1NotifyLabel->setText("[ player1NotifyLabel ]");
//    boardPlayer1->setObjectName("boardPlayer1Widget");

//    player1GameBox->setParent(gameBox);

//    player1GameBox->setGeometry(0,
//                                0,
//                                (gameBox->width() / 2) - 20,
//                                gameBox->height()
//                                );

//    player1NotifyLabel->setGeometry(0,0, player1GameBox->width(), 90);
//    player1NotifyLabel->setAlignment(Qt::AlignCenter);

//    speedUpCounterPlayer1->setGeometry(player1GameBox->width() - 160,
//                                player1GameBox->height() - 40,
//                                160,
//                                40);
//    coinsWidgetPlayer1->setGeometry(0,
//                                player1GameBox->height() - 40,
//                                160,
//                                40);
//    shopPlayer1->setGeometry(player1GameBox->width() / 2 - 150,
//                             player1GameBox->height() - 40,
//                             300,
//                             40);
//    boardPlayer1->setGeometry(0,
//                              90,
//                              player1GameBox->width(),
//                              player1GameBox->height() - 150);

//    player1NotifyLabel->setParent(player1GameBox);
//    speedUpCounterPlayer1->setParent(player1GameBox);
//    coinsWidgetPlayer1->setParent(player1GameBox);
//    shopPlayer1->setParent(player1GameBox);
//    boardPlayer1->setParent(player1GameBox);


//    connect(this, SIGNAL(destroyed()), player1GameBox, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), player1NotifyLabel, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), speedUpCounterPlayer1, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer1, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), shopPlayer1, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), boardPlayer1, SLOT(deleteLater()));
//}

//void w_MainWindow::createPlayer2GmaeBox()
//{
//    player2GameBox = new QWidget();
//    player2NotifyLabel =  new QLabel();
//    speedUpCounterPlayer2 = new w_speedUpCounterWidget();
//    coinsWidgetPlayer2 = new w_coinsWidget();
//    shopPlayer2 = new w_shopWidget();
//    boardPlayer2 = new w_boardWidget();
//    player2GameBox->setObjectName("player2GameBoxWidget");
//    player2NotifyLabel->setObjectName("player2NotifyLabel");
//    player2NotifyLabel->setText("[ player2NotifyLabel ]");
//    boardPlayer2->setObjectName("boardPlayer2Widget");

//    player2GameBox->setParent(gameBox);

//    player2GameBox->setGeometry((gameBox->width() / 2) + 20,
//                                0,
//                                (gameBox->width() / 2) - 20,
//                                gameBox->height()
//                                );

//    player2NotifyLabel->setGeometry(0,0, player2GameBox->width(), 90);
//    player2NotifyLabel->setAlignment(Qt::AlignCenter);

//    speedUpCounterPlayer2->setGeometry(0,
//                                       player2GameBox->height() - 40,
//                                       160,
//                                       40);
//    coinsWidgetPlayer2->setGeometry(player2GameBox->width() - 100,
//                                  player2GameBox->height() - 40,
//                                  100,
//                                  40);
//    shopPlayer2->setGeometry(player2GameBox->width() / 2 - 150,
//                             player2GameBox->height() - 40,
//                             300,
//                             40);
//    boardPlayer2->setGeometry(0,
//                              90,
//                              player2GameBox->width(),
//                              player2GameBox->height() - 150);

//    player2NotifyLabel->setParent(player2GameBox);
//    speedUpCounterPlayer2->setParent(player2GameBox);
//    coinsWidgetPlayer2->setParent(player2GameBox);
//    shopPlayer2->setParent(player2GameBox);
//    boardPlayer2->setParent(player2GameBox);

//    connect(this, SIGNAL(destroyed()), player2GameBox, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), player2NotifyLabel, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), speedUpCounterPlayer2, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer2, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), shopPlayer2, SLOT(deleteLater()));
//    connect(this, SIGNAL(destroyed()), boardPlayer2, SLOT(deleteLater()));
//}

//void w_MainWindow::createLobbyBoxWidget()
//{
//    lobbyBox = new w_lobbyBoxWidget(gameBox->width(), 150, gameBox);
//    lobbyBox->setObjectName("lobbyBox");
//    lobbyBox->show();
//}

//void w_MainWindow::createGamesListBoxWidget()
//{
//    w_gamesListWidget * gamesListBox = new w_gamesListWidget(QList<game::gameInformations>(), gameBox->width(), gameBox->height() - 150, gameBox);
//    connect(this, SIGNAL(refreshGamesList(QList<game::gameInformations>)), gamesListBox, SLOT(loadGamesList(QList<game::gameInformations>)));
//    gamesListBox->setObjectName("gamesListBox");
//    gamesListBox->setGeometry(0, 150, gameBox->width(), gameBox->height() - 150);
//}


void w_MainWindow::joinButtonPressed()
{
    QMessageBox msgBox;
    msgBox.setText("Join button pressed.");
    msgBox.exec();
}

void w_MainWindow::newButtonPressed()
{
    createNewGameInterface();
    emit newGameButtonPressed();
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

void w_MainWindow::backButtonPressed()
{
    createMainMenuInterface();
}

//void w_MainWindow::nullptrLobbyBox()
//{
//    lobbyBox = nullptr;
//}

bool w_MainWindow::getGfullscreen_mode() const
{
    return gfullscreen_mode;
}

void w_MainWindow::setGfullscreen_mode(bool newGfullscreen_mode)
{
    gfullscreen_mode = newGfullscreen_mode;
}

//void w_MainWindow::loadPlayer1Board(const board::boardArray &board)
//{
//    boardPlayer1->loadBoard(board);
//}

//void w_MainWindow::loadPlayer2Board(const board::boardArray &board)
//{
//    boardPlayer2->loadBoard(board);
//}

//void w_MainWindow::loadPlayer1Snake(c_snake *snake)
//{
//    w_board::w_snake tempSn;

//    for(int iii=0; iii<snake->getSnake().size(); iii++) {
//        w_board::w_snakePart tempPart;

//        tempPart.x = snake->getSnake()[iii].x();
//        tempPart.y = snake->getSnake()[iii].y();
//        if(iii == 0) {
//            switch (snake->getDirection()) {
//            case snake::MOVE_UP: {
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_UP);
//                break;
//            }
//            case snake::MOVE_RIGHT: {
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_RIGHT);
//                break;
//            }
//            case snake::MOVE_DOWN: {
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_DOWN);
//                break;
//            }
//            case snake::MOVE_LEFT: {
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_LEFT);
//                break;
//            }
//            default: {
//                break;
//            }
//            }
//        } else if(iii == snake->getSnake().size()-1) {
//            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() > snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_UP);
//            else if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() < snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_DOWN);
//            else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() == snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_LEFT);
//            else
//                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_RIGHT);
//        } else {

//            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x()) {

//                if(snake->getSnake()[iii+1].x() == snake->getSnake()[iii].x()) {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_VERTICAL);
//                } else if(snake->getSnake()[iii+1].x() > snake->getSnake()[iii].x()){
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RT);
//                } else {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LT);
//                }

//            } else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() ) {

//                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_HORIZONTAL);
//                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RB);
//                } else {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RT);
//                }

//            } else {

//                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_HORIZONTAL);
//                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LB);
//                } else {
//                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LT);
//                }
//            }
//        }
//        tempSn.append(tempPart);
//    }

//    boardPlayer1->loadSnake(tempSn);
//}

//void w_MainWindow::loadPlayer2Snake(c_snake *snake)
//{
//    w_board::w_snake tempSn;

//    for(int iii=0; iii<snake->getSnake().size(); iii++) {
//        w_board::w_snakePart tempPart;

//        tempPart.x = snake->getSnake()[iii].x();
//        tempPart.y = snake->getSnake()[iii].y();
//        if(iii == 0) {
//            switch (snake->getDirection()) {
//            case snake::MOVE_UP: {
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_UP);
//                break;
//            }
//            case snake::MOVE_RIGHT: {
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_RIGHT);
//                break;
//            }
//            case snake::MOVE_DOWN: {
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_DOWN);
//                break;
//            }
//            case snake::MOVE_LEFT: {
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_LEFT);
//                break;
//            }
//            default: {
//                break;
//            }
//            }
//        } else if(iii == snake->getSnake().size()-1) {
//            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() > snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_UP);
//            else if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() < snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_DOWN);
//            else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() == snake->getSnake()[iii].y() )
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_LEFT);
//            else
//                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_RIGHT);
//        } else {

//            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x()) {

//                if(snake->getSnake()[iii+1].x() == snake->getSnake()[iii].x()) {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_VERTICAL);
//                } else if(snake->getSnake()[iii+1].x() > snake->getSnake()[iii].x()){
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RT);
//                } else {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LT);
//                }

//            } else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() ) {

//                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_HORIZONTAL);
//                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RB);
//                } else {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RT);
//                }

//            } else {

//                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_HORIZONTAL);
//                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LB);
//                } else {
//                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LT);
//                }
//            }
//        }
//        tempSn.append(tempPart);
//    }

//    boardPlayer2->loadSnake(tempSn);
//}

//void w_MainWindow::refreshPlayer1Board(const board::boardArray &board, const c_snake &snake)
//{
//    if(!refreshBoardStatus) return;
//    boardPlayer1->refreshBoard(board);
//    refreshPlayer1Snake(snake);
//}

//void w_MainWindow::refreshPlayer1Snake(const c_snake &snake)
//{
//    if(!refreshBoardStatus) return;
//    loadPlayer1Snake(const_cast<c_snake *>(&snake));
//}

//void w_MainWindow::refreshPlayer1Coins(qint32 coins)
//{
//    if(!refreshBoardStatus) return;
//    coinsWidgetPlayer1->setCoinsNumberText(coins);
//}

//void w_MainWindow::refreshPlayer2Board(const board::boardArray &board, const c_snake &snake)
//{
//    if(!refreshBoardStatus) return;
//    boardPlayer2->refreshBoard(board);
//    refreshPlayer2Snake(snake);
//}

//void w_MainWindow::refreshPlayer2Snake(const c_snake &snake)
//{
//    if(!refreshBoardStatus) return;
//    loadPlayer2Snake(const_cast<c_snake *>(&snake));
//}

//void w_MainWindow::refreshPlayer2Coins(qint32 coins)
//{
//    if(!refreshBoardStatus) return;
//    coinsWidgetPlayer2->setCoinsNumberText(coins);
//}

//void w_MainWindow::refrshSpeedUpCounter(QPair<bool, bool> player, int time)
//{
//    if(player.first)
//        speedUpCounterPlayer1->setLabelText(time);
//    if(player.second)
//        speedUpCounterPlayer2->setLabelText(time);
//}

//void w_MainWindow::resetSpeedUpCounter(QPair<bool, bool> player)
//{
//    if(player.first)
//        speedUpCounterPlayer1->setLabelText(0);
//    if(player.second)
//        speedUpCounterPlayer2->setLabelText(0);
//}

//void w_MainWindow::refreshSpeedUpCounterLevelLabel(QPair<bool, bool> player, quint8 speedUpLevel)
//{
//    if(player.first)
//        speedUpCounterPlayer1->setLevelLabelText(speedUpLevel);
//    if(player.second)
//        speedUpCounterPlayer2->setLevelLabelText(speedUpLevel);
//}

//void w_MainWindow::showNotification(QPair<bool, bool> player, QString msg)
//{
//    if(player.first)
//        player1NotifyLabel->setText(msg);
//    if(player.second)
//        player2NotifyLabel->setText(msg);
//}

//void w_MainWindow::refreshLobbiesListBox(QList<lobby::lobbyInformations> lobbiesInfo)
//{
//    emit refreshGamesList(lobbiesInfo);
//}

void w_MainWindow::refreshLobbyBox(lobby::lobbyInformations lobbyInfo)
{
    emit refreshLobbyBoxSignal(lobbyInfo);
}

void w_MainWindow::refreshLobbiesListBox(const QList<lobby::lobbyInformations> &lobbiesInfos)
{
    emit refreshLobbiesListBoxSignal(lobbiesInfos);
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




