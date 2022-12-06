#ifndef W_LOBBYBOXWIDGET_H
#define W_LOBBYBOXWIDGET_H

#include "_myData.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextCursor>
#include <QGridLayout>

#define _MAX_TEXT_EDIT_LENGTH_ 32

class w_lobbyBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit w_lobbyBoxWidget(int GWidth, int GHeight, QWidget *parent = nullptr);
    ~w_lobbyBoxWidget();


public slots:
    void loadGameInfo(lobby::lobbyInformations lobbyInfo);

private:
    QWidget *lobbyNameTextEdit;
    QWidget *playerNameTextEdit;
    QWidget *enemyNameLabel;
    QWidget *playerReadyCheckBox;
    QWidget *enemyReadyCheckBox;
    QWidget *enableLobbyNameEditPushButton;
    QWidget *enablePlayerNameEditPushButton;
    QWidget *enableEnemyNameEditPushButton;
    QWidget *ownerNameLabel;

    QWidget *playerBox;
    QWidget *enemyBox;
    QWidget *playerOneLabel;
    QWidget *playerTwoLabel;
    QWidget *centralWidget;

private slots:
    void lobbyNameTextEditTextEditFinished();
    void playerNameTextEditTextEditFinished();
    void enableLobbyNameEditPushButtonClicked(bool checked);
    void enablePlayerNameEditPushButtonClicked(bool checked);
    void playerReadyCheckBoxChanged(int checkState);
    void enemyReadyCheckBoxChanged(int checkState);

signals:

};

#endif // W_LOBBYBOXWIDGET_H
