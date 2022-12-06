#ifndef W_MAINMENUINTERFACE_H
#define W_MAINMENUINTERFACE_H

#include "w_userinterface.h"

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>


class w_MainMenuInterface : public w_UserInterface
{
    Q_OBJECT
public:
    w_MainMenuInterface(int Gwidth, int Gheight, QWidget *parent = nullptr);
    ~w_MainMenuInterface();

public slots:

private:
    QWidget *settingsButton;
    QWidget *closeButton;
    QWidget *joinButton;
    QWidget *newButton;

    void createTopBox() override;
    void createCentralBox() override;
    void createBottomBox() override;

private slots:
    void joinButtonPressed(bool checked);
    void newButtonPressed(bool checked);
    void settingsButtonPressed(bool checked);
    void closeButtonPressed(bool checked);

signals:
    void newGameButtonPressed(bool checked);
    void joinGameButtonPressed(bool checked);
    void settingsGameButtonPressed(bool checked);
    void closeGameButtonPressed(bool checked);

};

#endif // W_MAINMENUINTERFACE_H
