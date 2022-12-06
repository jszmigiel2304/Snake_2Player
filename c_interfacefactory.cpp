#include "c_interfacefactory.h"
#include "w_tpbutton.h"
#include "w_mainmenuinterface.h"
#include "w_newgameinterface.h"
#include "w_lobbyboxwidget.h"
#include "w_lbeditbutton.h"
#include "w_lblabel.h"
#include "w_lblineedit.h"
#include "w_lbckeckbox.h"
#include "w_gljoinbutton.h"
#include "w_gllabel.h"
#include "w_gameslistwidget.h"
#include "w_gameslistitemWidget.h"

c_interfaceFactory::c_interfaceFactory(QObject *parent)
    : QObject{parent}
{

}

c_interfaceFactory::~c_interfaceFactory()
{

}

QWidget *c_interfaceFactory::createWidget(Interface_NS::WidgetType type, QWidget *parent, QObject * eventFilter)
{
    switch (type) {
    case Interface_NS::WT_TP_BUTTON: return new w_tpButton(parent, eventFilter);
    case Interface_NS::WT_LOBBY_BOX: return new w_lobbyBoxWidget(parent->width(), 150, parent);
    case Interface_NS::WT_GAMES_LIST_BOX: return new w_gamesListWidget(parent->width(), 50, parent);
    case Interface_NS::WT_GAMES_LIST_BOX_ITEM: return new w_gamesListItemWidget(parent->width(), 50, parent);
    case Interface_NS::WT_LW_LABEL: return new w_lbLabel(parent, eventFilter);
    case Interface_NS::WT_LW_EDIT_BUTTON: return new w_lbEditButton(parent, eventFilter);
    case Interface_NS::WT_LW_LINE_EDIT: return new w_lbLineEdit(parent, eventFilter);
    case Interface_NS::WT_LW_CHECK_BOX: return new w_lbCkeckBox(parent, eventFilter);
    case Interface_NS::WT_GLW_LABEL: return new w_glLabel(parent, eventFilter);
    case Interface_NS::WT_GLW_BUTTON: return new w_glJoinButton(parent, eventFilter);
    default: return nullptr;
    }
}

QWidget *c_interfaceFactory::createUserInterface(Interface_NS::InterfaceType type, QWidget *parent)
{
    switch (type) {
    case Interface_NS::IT_MAIN_MENU: return new w_MainMenuInterface(parent->width(), parent->height(), parent);
    case Interface_NS::IT_NEW_GAME: return new w_NewGameInterface(parent->width(), parent->height(), parent);
    default: return nullptr;
    }
}
