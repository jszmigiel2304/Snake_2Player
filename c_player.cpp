#include "c_player.h"
#include "c_parser.h"

c_player::c_player(QObject *parent)
    : QObject{parent}
{    
    name = "DEFAULT_PLAYER_NAME";
}

c_player::~c_player()
{
}


void c_player::setName(const QString &newName)
{
    name = newName;
}
const QString &c_player::getName() const
{
    return name;
}
