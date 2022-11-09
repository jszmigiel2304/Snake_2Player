#ifndef W_MAINWINDOW_H
#define W_MAINWINDOW_H

#include "c_myinterfaceeventfilter.h"
#include "w_speedupcounterwidget.h"
#include "w_coinswidget.h"
#include "w_shopwidget.h"

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

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QWidget *central;
    QHBoxLayout centralLayout;
    QWidget *topBox;
    QWidget *gameBox;
    QWidget *player1GameBox;
    QWidget *player2GameBox;
    w_speedUpCounterWidget *sppedUpCounterPlayer1;
    w_speedUpCounterWidget *sppedUpCounterPlayer2;
    w_coinsWidget *coinsWidgetPlayer1;
    w_coinsWidget *coinsWidgetPlayer2;
    w_shopWidget *shopPlayer1;
    w_shopWidget *shopPlayer2;
    QWidget *boardPlayer1;
    QWidget *boardPlayer2;

//    QWidget *startButton;
//    QWidget *settingButton;
//    QWidget *closeButton;

    QPushButton *startButton;
    QPushButton *settingButton;
    QPushButton *closeButton;
    QPushButton *joinButton;
    QPushButton *newButton;

    QLabel *player1NotifyLabel;
    QLabel *player2NotifyLabel;

    c_myInterfaceEventFilter *myEventFilter;
    bool gfullscreen_mode;
    int gwidth;
    int gheight;

private slots:
    void joinButtonPressed();
    void newButtonPressed();
    void startButtonPressed();
    void settingsButtonPressed();
    void closeButtonPressed();

};
#endif // W_MAINWINDOW_H
