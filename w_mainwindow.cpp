#include "w_mainwindow.h"

w_MainWindow::w_MainWindow(QList<QPair<QString, QVariant>> settings, QWidget *parent)
    : QMainWindow(parent)
{
    myEventFilter = new c_myInterfaceEventFilter(this);
    connect(this, SIGNAL(destroyed()), myEventFilter, SLOT(deleteLater()));
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

    createInterface();
}

w_MainWindow::~w_MainWindow()
{
}

void w_MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void w_MainWindow::createInterface()
{
    central = new QWidget();
    topBox = new QWidget();
    gameBox = new QWidget();

    central->setObjectName("centralWidget");
    topBox->setObjectName("topBoxWidget");
    gameBox->setObjectName("gameBoxWidget");

    central->setMinimumHeight(getGheight());
    central->setMaximumHeight(getGheight());
    central->setMinimumWidth(getGwidth());
    central->setMaximumWidth(getGwidth());
    central->resize(getGwidth(), getGheight());

    gameBox->setGeometry(getGwidth() / 48,
                         (2 * (getGheight() / 54)) + 90,
                         getGwidth() - (2 * (getGwidth() / 48)),
                         getGheight() - 90 - (3 * (getGheight() / 54)));

    gameBox->setParent(central);


    createTopPanel();
    createPlayer1GmaeBox();
    createPlayer2GmaeBox();

    connect(this, SIGNAL(destroyed()), gameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), central, SLOT(deleteLater()));

    setCentralWidget(central);
}

void w_MainWindow::createTopPanel()
{
    startButton = new QPushButton();
    settingButton = new QPushButton();
    closeButton = new QPushButton();
    joinButton = new QPushButton();
    newButton = new QPushButton();

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

    startButton->setObjectName("startButtonWidget");
    settingButton->setObjectName("settingButtonWidget");
    closeButton->setObjectName("closeButtonWidget");
    joinButton->setObjectName("joinButtonWidget");
    newButton->setObjectName("newButtonWidget");

    topBox->setGeometry(getGwidth() / 48,
                         getGheight() / 54,
                         getGwidth() - (2 * (getGwidth() / 48)),
                         90);
    topBox->setParent(central);

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

    startButton->setParent(topBox);
    settingButton->setParent(topBox);
    closeButton->setParent(topBox);
    newButton->setParent(topBox);
    joinButton->setParent(topBox);

    connect(this, SIGNAL(destroyed()), topBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), startButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), settingButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), closeButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), newButton, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), joinButton, SLOT(deleteLater()));
}

void w_MainWindow::createPlayer1GmaeBox()
{
    player1GameBox = new QWidget();
    player1NotifyLabel =  new QLabel();
    sppedUpCounterPlayer1 = new w_speedUpCounterWidget();
    coinsWidgetPlayer1 = new w_coinsWidget();
    shopPlayer1 = new w_shopWidget();
    boardPlayer1 = new w_boardWidget();
    player1GameBox->setObjectName("player1GameBoxWidget");
    player1NotifyLabel->setObjectName("player1NotifyLabel");
    player1NotifyLabel->setText("[ player1NotifyLabel ]");
    boardPlayer1->setObjectName("boardPlayer1Widget");

    player1GameBox->setParent(gameBox);

    player1GameBox->setGeometry(0,
                                0,
                                (gameBox->width() / 2) - 20,
                                gameBox->height()
                                );

    player1NotifyLabel->setGeometry(0,0, player1GameBox->width(), 90);
    player1NotifyLabel->setAlignment(Qt::AlignCenter);

    sppedUpCounterPlayer1->setGeometry(player1GameBox->width() - 100,
                                player1GameBox->height() - 40,
                                100,
                                40);
    coinsWidgetPlayer1->setGeometry(0,
                                player1GameBox->height() - 40,
                                100,
                                40);
    shopPlayer1->setGeometry(player1GameBox->width() / 2 - 150,
                             player1GameBox->height() - 40,
                             300,
                             40);
    boardPlayer1->setGeometry(0,
                              90,
                              player1GameBox->width(),
                              player1GameBox->height() - 150);

    player1NotifyLabel->setParent(player1GameBox);
    sppedUpCounterPlayer1->setParent(player1GameBox);
    coinsWidgetPlayer1->setParent(player1GameBox);
    shopPlayer1->setParent(player1GameBox);
    boardPlayer1->setParent(player1GameBox);


    connect(this, SIGNAL(destroyed()), player1GameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player1NotifyLabel, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), sppedUpCounterPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), shopPlayer1, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), boardPlayer1, SLOT(deleteLater()));
}

void w_MainWindow::createPlayer2GmaeBox()
{
    player2GameBox = new QWidget();
    player2NotifyLabel =  new QLabel();
    sppedUpCounterPlayer2 = new w_speedUpCounterWidget();
    coinsWidgetPlayer2 = new w_coinsWidget();
    shopPlayer2 = new w_shopWidget();
    boardPlayer2 = new w_boardWidget();
    player2GameBox->setObjectName("player2GameBoxWidget");
    player2NotifyLabel->setObjectName("player2NotifyLabel");
    player2NotifyLabel->setText("[ player2NotifyLabel ]");
    boardPlayer2->setObjectName("boardPlayer2Widget");

    player2GameBox->setParent(gameBox);

    player2GameBox->setGeometry((gameBox->width() / 2) + 20,
                                0,
                                (gameBox->width() / 2) - 20,
                                gameBox->height()
                                );

    player2NotifyLabel->setGeometry(0,0, player2GameBox->width(), 90);
    player2NotifyLabel->setAlignment(Qt::AlignCenter);

    sppedUpCounterPlayer2->setGeometry(0,
                                       player2GameBox->height() - 40,
                                       100,
                                       40);
    coinsWidgetPlayer2->setGeometry(player2GameBox->width() - 100,
                                  player2GameBox->height() - 40,
                                  100,
                                  40);
    shopPlayer2->setGeometry(player2GameBox->width() / 2 - 150,
                             player2GameBox->height() - 40,
                             300,
                             40);
    boardPlayer2->setGeometry(0,
                              90,
                              player2GameBox->width(),
                              player2GameBox->height() - 150);

    player2NotifyLabel->setParent(player2GameBox);
    sppedUpCounterPlayer2->setParent(player2GameBox);
    coinsWidgetPlayer2->setParent(player2GameBox);
    shopPlayer2->setParent(player2GameBox);
    boardPlayer2->setParent(player2GameBox);

    connect(this, SIGNAL(destroyed()), player2GameBox, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), player2NotifyLabel, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), sppedUpCounterPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), coinsWidgetPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), shopPlayer2, SLOT(deleteLater()));
    connect(this, SIGNAL(destroyed()), boardPlayer2, SLOT(deleteLater()));
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

void w_MainWindow::loadPlayer1Board(const board::boardArray &board)
{
    boardPlayer1->loadBoard(board);
}

void w_MainWindow::loadPlayer2Board(const board::boardArray &board)
{
    boardPlayer2->loadBoard(board);
}

void w_MainWindow::loadPlayer1Snake(c_snake *snake)
{
    w_board::w_snake tempSn;

    for(int iii=0; iii<snake->getSnake().size(); iii++) {
        w_board::w_snakePart tempPart;

        tempPart.x = snake->getSnake()[iii].x();
        tempPart.y = snake->getSnake()[iii].y();
        if(iii == 0) {
            switch (snake->getDirection()) {
            case snake::MOVE_UP: {
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_UP);
                break;
            }
            case snake::MOVE_RIGHT: {
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_RIGHT);
                break;
            }
            case snake::MOVE_DOWN: {
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_DOWN);
                break;
            }
            case snake::MOVE_LEFT: {
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_HEAD_LEFT);
                break;
            }
            default: {
                break;
            }
            }
        } else if(iii == snake->getSnake().size()-1) {
            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() > snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_UP);
            else if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() < snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_DOWN);
            else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() == snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_LEFT);
            else
                tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_TAIL_RIGHT);
        } else {

            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x()) {

                if(snake->getSnake()[iii+1].x() == snake->getSnake()[iii].x()) {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_VERTICAL);
                } else if(snake->getSnake()[iii+1].x() > snake->getSnake()[iii].x()){
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RT);
                } else {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LT);
                }

            } else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() ) {

                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_HORIZONTAL);
                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RB);
                } else {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_RT);
                }

            } else {

                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_HORIZONTAL);
                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LB);
                } else {
                    tempPart.pixmap = boardPlayer1->getIcon(board::SNAKE_BODY_BEND_LT);
                }
            }
        }
        tempSn.append(tempPart);
    }

    boardPlayer1->loadSnake(tempSn);
}

void w_MainWindow::loadPlayer2Snake(c_snake *snake)
{
    w_board::w_snake tempSn;

    for(int iii=0; iii<snake->getSnake().size(); iii++) {
        w_board::w_snakePart tempPart;

        tempPart.x = snake->getSnake()[iii].x();
        tempPart.y = snake->getSnake()[iii].y();
        if(iii == 0) {
            switch (snake->getDirection()) {
            case snake::MOVE_UP: {
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_UP);
                break;
            }
            case snake::MOVE_RIGHT: {
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_RIGHT);
                break;
            }
            case snake::MOVE_DOWN: {
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_DOWN);
                break;
            }
            case snake::MOVE_LEFT: {
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_HEAD_LEFT);
                break;
            }
            default: {
                break;
            }
            }
        } else if(iii == snake->getSnake().size()-1) {
            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() > snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_UP);
            else if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() < snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_DOWN);
            else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() && snake->getSnake()[iii-1].y() == snake->getSnake()[iii].y() )
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_LEFT);
            else
                tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_TAIL_RIGHT);
        } else {

            if( snake->getSnake()[iii-1].x() == snake->getSnake()[iii].x()) {

                if(snake->getSnake()[iii+1].x() == snake->getSnake()[iii].x()) {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_VERTICAL);
                } else if(snake->getSnake()[iii+1].x() > snake->getSnake()[iii].x()){
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RT);
                } else {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LT);
                }

            } else if( snake->getSnake()[iii-1].x() > snake->getSnake()[iii].x() ) {

                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_HORIZONTAL);
                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RB);
                } else {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_RT);
                }

            } else {

                if(snake->getSnake()[iii+1].y() == snake->getSnake()[iii].y()) {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_HORIZONTAL);
                } else if(snake->getSnake()[iii+1].y() > snake->getSnake()[iii].y()){
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LB);
                } else {
                    tempPart.pixmap = boardPlayer2->getIcon(board::SNAKE_BODY_BEND_LT);
                }
            }
        }
        tempSn.append(tempPart);
    }

    boardPlayer2->loadSnake(tempSn);
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




