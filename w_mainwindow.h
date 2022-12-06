#ifndef W_MAINWINDOW_H
#define W_MAINWINDOW_H

#include "c_myinterfaceeventfilter.h"
#include "w_speedupcounterwidget.h"
#include "w_coinswidget.h"
#include "w_shopwidget.h"
#include "w_boardwidget.h"
#include "w_lobbyboxwidget.h"
#include "w_gameslistwidget.h"
#include "_myData.h"

#include <QMainWindow>
#include <QTimer>
#include <QCloseEvent>
#include <QList>
#include <QVariant>
#include <QPair>
#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMetaObject>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPointer>
#include <QAction>


class w_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit w_MainWindow(QList<QPair<QString, QVariant>> settings, QWidget *parent = nullptr);
    ~w_MainWindow();


    int getGwidth() const;
    void setGwidth(int newGwidth);

    int getGheight() const;
    void setGheight(int newGheight);

    bool getGfullscreen_mode() const;
    void setGfullscreen_mode(bool newGfullscreen_mode);

//    w_boardWidget *getBoardPlayer1() const;
//    void setBoardPlayer1(w_boardWidget *newBoardPlayer1);
//    w_boardWidget *getBoardPlayer2() const;
//    void setBoardPlayer2(w_boardWidget *newBoardPlayer2);
//    const w_board::w_snake &getSnakePlayer1() const;
//    void setSnakePlayer1(const w_board::w_snake &newSnakePlayer1);
//    const w_board::w_snake &getSnakePlayer2() const;
//    void setSnakePlayer2(const w_board::w_snake &newSnakePlayer2);

public slots:
    //void stopRefreshing();

//    void loadPlayer1Board(const board::boardArray &board);
//    void loadPlayer2Board(const board::boardArray &board);
//    void loadPlayer1Snake(c_snake *snake);
//    void loadPlayer2Snake(c_snake *snake);

//    void refreshPlayer1Board(const board::boardArray &board, const c_snake &snake);
//    void refreshPlayer1Snake(const c_snake &snake);
//    void refreshPlayer1Coins(qint32 coins);
//    void refreshPlayer2Board(const board::boardArray &board, const c_snake &snake);
//    void refreshPlayer2Snake(const c_snake &snake);
//    void refreshPlayer2Coins(qint32 coins);

//    void refrshSpeedUpCounter(QPair<bool, bool> player, int time);
//    void resetSpeedUpCounter(QPair<bool, bool> player);
//    void refreshSpeedUpCounterLevelLabel(QPair<bool, bool> player, quint8 speedUpLevel);

//    void showNotification(QPair<bool, bool> player, QString msg);

//    void refreshLobbiesListBox(QList<lobby::lobbyInformations> lobbiesInfo);
    void refreshLobbyBox(lobby::lobbyInformations lobbyInfo);
    void refreshLobbiesListBox(const QList<lobby::lobbyInformations> &lobbiesInfos);
//    void removeLobbyBox();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    bool refreshBoardStatus;

    QPointer<QWidget> central;
    //QHBoxLayout centralLayout;
    //QWidget *topBox;
//    QWidget *gameBox;
//    QWidget *player1GameBox;
//    QWidget *player2GameBox;
//    w_speedUpCounterWidget *speedUpCounterPlayer1;
//    w_speedUpCounterWidget *speedUpCounterPlayer2;
//    w_coinsWidget *coinsWidgetPlayer1;
//    w_coinsWidget *coinsWidgetPlayer2;
//    w_shopWidget *shopPlayer1;
//    w_shopWidget *shopPlayer2;

//    w_boardWidget *boardPlayer1;
//    w_boardWidget *boardPlayer2;

//    w_board::w_snake snakePlayer1;
//    w_board::w_snake snakePlayer2;

//    QLabel *player1NotifyLabel;
//    QLabel *player2NotifyLabel;

    bool gfullscreen_mode;
    int gwidth;
    int gheight;

    void createMainMenuInterface();
    void createNewGameInterface();

//    void createTopPanel();
//    void createPlayer1GmaeBox();
//    void createPlayer2GmaeBox();
//    void createLobbyBoxWidget();
//    void createGamesListBoxWidget();


private slots:
    void joinButtonPressed();
    void newButtonPressed();
    void startButtonPressed();
    void settingsButtonPressed();
    void closeButtonPressed();
    void backButtonPressed();

signals:
    void newGameButtonPressed();
    void refreshLobbyBoxSignal(lobby::lobbyInformations lobbyInfo);
    void refreshLobbiesListBoxSignal(const QList<lobby::lobbyInformations> &lobbiesInfos);

};
#endif // W_MAINWINDOW_H
