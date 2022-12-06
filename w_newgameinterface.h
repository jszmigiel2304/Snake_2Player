#ifndef W_NEWGAMEINTERFACE_H
#define W_NEWGAMEINTERFACE_H

#include "_myData.h"
#include "w_userinterface.h"

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>

class w_NewGameInterface : public w_UserInterface
{
    Q_OBJECT
public:
    w_NewGameInterface(int Gwidth, int Gheight, QWidget *parent = nullptr);
    ~w_NewGameInterface();

public slots:
    void refreshLobbyBox(lobby::lobbyInformations lobbyInfo);
    void refreshLobbiesListBox(const QList<lobby::lobbyInformations> &lobbiesInfos);

private:
    QWidget *settingsButton;
    QWidget *closeButton;
    QWidget *backButton;
    QWidget *lobbyBox;
    QWidget *gamesListBox;

    void createTopBox() override;
    void createCentralBox() override;
    void createBottomBox() override;

private slots:
    void backButtonPressed(bool checked);
    void settingsButtonPressed(bool checked);
    void closeButtonPressed(bool checked);

signals:
    void backGameButtonPressed(bool checked);
    void settingsGameButtonPressed(bool checked);
    void closeGameButtonPressed(bool checked);
};

#endif // W_NEWGAMEINTERFACE_H
