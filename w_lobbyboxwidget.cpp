#include "w_lobbyboxwidget.h"
#include "c_interfacefactory.h"
#include "w_lbeditbutton.h"
#include "w_lblabel.h"
#include "w_lblineedit.h"
#include "w_lbckeckbox.h"

w_lobbyBoxWidget::w_lobbyBoxWidget(int GWidth, int GHeight, QWidget *parent)
    : QWidget{parent}
{    
    setMinimumSize(GWidth,GHeight);
    setMaximumSize(GWidth,GHeight);
    resize(GWidth, GHeight);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("background-color: rgba(255,255,255, 0.3);");

    centralWidget = new QWidget(this);
    centralWidget->setStyleSheet("background-color: rgba(255,255,255, 0.3);"
                                 "border-color: rgba(128,128,128,1);"
                                 "border-style: solid;"
                                 "border-top-width: 3px;"
                                 "border-left-width: 3px;"
                                 "border-right-width: 3px;"
                                 "border-bottom-width: 3px;");
    playerBox = new QWidget(centralWidget);
    playerBox->setStyleSheet("background-color: transparent;"
                             "border-color: rgba(128,128,128,1);"
                                 "border-style: solid;"
                                 "border-top-width: 3px;"
                                 "border-left-width: 0px;"
                                 "border-right-width: 4px;"
                                 "border-bottom-width: 0px;");
    enemyBox = new QWidget(centralWidget);
    enemyBox->setStyleSheet("background-color: transparent;"
                            "border-color: rgba(128,128,128,1);"
                                 "border-style: solid;"
                                "border-top-width: 3px;"
                                "border-left-width: 0px;"
                                "border-right-width: 0px;"
                                "border-bottom-width: 0px;");

    lobbyNameTextEdit = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LINE_EDIT, centralWidget);
    playerNameTextEdit = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LINE_EDIT, playerBox);
    enemyNameLabel = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LABEL, enemyBox);
    playerReadyCheckBox = c_interfaceFactory::createWidget(Interface_NS::WT_LW_CHECK_BOX, playerBox);
    enemyReadyCheckBox = c_interfaceFactory::createWidget(Interface_NS::WT_LW_CHECK_BOX, enemyBox);
    enablePlayerNameEditPushButton = c_interfaceFactory::createWidget(Interface_NS::WT_LW_EDIT_BUTTON, playerBox);
    enableLobbyNameEditPushButton = c_interfaceFactory::createWidget(Interface_NS::WT_LW_EDIT_BUTTON, centralWidget);
    ownerNameLabel = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LABEL, centralWidget);
    playerOneLabel = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LABEL, playerBox);
    playerTwoLabel = c_interfaceFactory::createWidget(Interface_NS::WT_LW_LABEL, enemyBox);

    centralWidget->setGeometry(0,0,GWidth,GHeight);

    dynamic_cast<w_lbLineEdit *>(lobbyNameTextEdit)->setText("lobbyNameTextEdit");
    dynamic_cast<w_lbLabel *>(ownerNameLabel)->setText("ownerNameLabel");
    dynamic_cast<w_lbLineEdit *>(playerNameTextEdit)->setText("playerNameTextEdit");
    dynamic_cast<w_lbLabel *>(enemyNameLabel)->setText("enemyNameLabel");

    enableLobbyNameEditPushButton->setGeometry(0, 0, 50, 50);
    lobbyNameTextEdit->setGeometry(50, 0, GWidth - 300, 50);
    ownerNameLabel->setGeometry(GWidth - 250, 0, 250, 50);

    playerBox->setGeometry(0, 50, GWidth / 2, 100);
    enemyBox->setGeometry(GWidth / 2, 50, GWidth / 2, 100);

    playerOneLabel->setGeometry(0,0,playerBox->width(), 50);
    playerTwoLabel->setGeometry(0,0,enemyBox->width(), 50);

    dynamic_cast<w_lbLabel *>(playerOneLabel)->setText("Player ONE");
    dynamic_cast<w_lbLabel *>(playerTwoLabel)->setText("Player TWO");

    enablePlayerNameEditPushButton->setGeometry(0,50,50, 50);
    playerNameTextEdit->setGeometry(50,50,playerBox->width()-100, 50);
    playerReadyCheckBox->setGeometry(playerBox->width()-50,50,50, 50);

    enemyNameLabel->setGeometry(0,50,playerBox->width()-50, 50);
    enemyReadyCheckBox->setGeometry(playerBox->width()-50,50,50, 50);

    connect(dynamic_cast<w_lbLineEdit *>(lobbyNameTextEdit), SIGNAL(editingFinished()), this, SLOT(lobbyNameTextEditTextEditFinished()));
    connect(dynamic_cast<w_lbLineEdit *>(playerNameTextEdit), SIGNAL(editingFinished()), this, SLOT(playerNameTextEditTextEditFinished()));

    lobbyNameTextEdit->setEnabled(false);
    playerNameTextEdit->setEnabled(false);
    dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->setMaxLength(_MAX_TEXT_EDIT_LENGTH_);
    dynamic_cast<QLineEdit *>(playerNameTextEdit)->setMaxLength(_MAX_TEXT_EDIT_LENGTH_);

    connect(dynamic_cast<w_lbEditButton *>(enableLobbyNameEditPushButton), SIGNAL(clicked(bool)), this, SLOT(enableLobbyNameEditPushButtonClicked(bool)));
    connect(dynamic_cast<w_lbEditButton *>(enablePlayerNameEditPushButton), SIGNAL(clicked(bool)), this, SLOT(enablePlayerNameEditPushButtonClicked(bool)));

    enemyBox->setEnabled(false);
}


w_lobbyBoxWidget::~w_lobbyBoxWidget()
{

}

void w_lobbyBoxWidget::loadGameInfo(lobby::lobbyInformations lobbyInfo)
{
    dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->setText(lobbyInfo.lobbyName);
    dynamic_cast<QLineEdit *>(playerNameTextEdit)->setText(lobbyInfo.playersNames.first);
    dynamic_cast<QLabel *>(enemyNameLabel)->setText(lobbyInfo.playersNames.second);
    dynamic_cast<QCheckBox *>(playerReadyCheckBox)->setChecked(lobbyInfo.playersReadyCheck.first);
    dynamic_cast<QCheckBox *>(enemyReadyCheckBox)->setChecked(lobbyInfo.playersReadyCheck.second);

    if(lobbyInfo.ownerName.size() > 10)
        dynamic_cast<QLabel *>(ownerNameLabel)->setText( QString("%1...").arg(lobbyInfo.ownerName.first(10)));
    else
        dynamic_cast<QLabel *>(ownerNameLabel)->setText(lobbyInfo.ownerName);
}


void w_lobbyBoxWidget::lobbyNameTextEditTextEditFinished()
{
    lobbyNameTextEdit->setEnabled(false);
}

void w_lobbyBoxWidget::playerNameTextEditTextEditFinished()
{
    playerNameTextEdit->setEnabled(false);
}

void w_lobbyBoxWidget::enableLobbyNameEditPushButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    lobbyNameTextEdit->setEnabled(true);
    lobbyNameTextEdit->setFocus();
    dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->setCursorPosition(dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->text().length());
    dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->setSelection(0, dynamic_cast<QLineEdit *>(lobbyNameTextEdit)->text().length());
}

void w_lobbyBoxWidget::enablePlayerNameEditPushButtonClicked(bool checked)
{
    Q_UNUSED(checked)
    playerNameTextEdit->setEnabled(true);
    playerNameTextEdit->setFocus();
    dynamic_cast<QLineEdit *>(playerNameTextEdit)->setCursorPosition(dynamic_cast<QLineEdit *>(playerNameTextEdit)->text().length());
    dynamic_cast<QLineEdit *>(playerNameTextEdit)->setSelection(0, dynamic_cast<QLineEdit *>(playerNameTextEdit)->text().length());
}

void w_lobbyBoxWidget::playerReadyCheckBoxChanged(int checkState)
{
}

void w_lobbyBoxWidget::enemyReadyCheckBoxChanged(int checkState)
{

}

