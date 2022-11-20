#include "c_myqapplication.h"
#include "_defaultProperties.h"

c_MyQApplication::c_MyQApplication(int &argc, char **argv) : QApplication(argc, argv)
{
    setApplicationName("Snake multiplayer via TcpServer");
    setApplicationDisplayName("Snake multiplayer via TcpServer");

    configFileName = applicationDirPath() + "/config.ini" ;

    if(!QFileInfo::exists(configFileName)) {
        error("Nie znaleziono pliku config.ini");
        exit(0);
    } else {
        QSettings sett( applicationDirPath() + "/config.ini", QSettings::IniFormat);
        sett.beginGroup("style_sheets");
        stylesheetFileName = sett.value("used_file_name").toString();
        sett.endGroup();
    }

    QFile stylesheetFile( applicationDirPath() + QString("/%1").arg(stylesheetFileName) );
    if(stylesheetFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(stylesheetFile.readAll());
        setStyleSheet(styleSheet);
        stylesheetFile.close();
    } else {
        error("Nie znaleziono pliku stylesheet.qss");
        exit(0);
    }

    loadIcons();
}

c_MyQApplication::~c_MyQApplication()
{
    qDeleteAll(icons->begin(), icons->end());
    icons->clear();
    delete icons;

}

QList<QPair<QString, QVariant> > c_MyQApplication::getWindowProperties()
{
    if(!configFileName.isEmpty()) return getWindowProperties(configFileName);

    QList<QPair<QString, QVariant>> list;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    list.append( QPair<QString, QVariant>("fullscreen_mode", WINDOW_FULLSCREEN_MODE) );
    list.append( QPair<QString, QVariant>("width", screenGeometry.width()) );
    list.append( QPair<QString, QVariant>("height", screenGeometry.height()) );


    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getWindowProperties(const QString &fileName)
{
    QList<QPair<QString, QVariant>> list;

    QSettings sett( fileName, QSettings::IniFormat);
    sett.beginGroup("window");

    QPair<QString, QVariant> pair;

    foreach (const QString &childKey, sett.childKeys())
    {
        list.append( QPair<QString, QVariant>(childKey, sett.value(childKey)) );
    }

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    list.append( QPair<QString, QVariant>("width", screenGeometry.width()) );
    list.append( QPair<QString, QVariant>("height", screenGeometry.height()) );

    sett.endGroup();

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getServerProperties()
{
    if(!configFileName.isEmpty()) return getServerProperties(configFileName);

    QList<QPair<QString, QVariant>> list;

    list.append( QPair<QString, QVariant>("host", SERVER_HOST) );
    list.append( QPair<QString, QVariant>("port", SERVER_PORT) );

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getServerProperties(const QString &fileName)
{
    QList<QPair<QString, QVariant>> list;

    QSettings sett( fileName, QSettings::IniFormat);
    sett.beginGroup("server");

    QPair<QString, QVariant> pair;

    foreach (const QString &childKey, sett.childKeys())
    {
        list.append( QPair<QString, QVariant>(childKey, sett.value(childKey)) );
    }

    sett.endGroup();

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getPlayer1Properties()
{
    if(!configFileName.isEmpty()) return getPlayer1Properties(configFileName);

    QList<QPair<QString, QVariant>> list;

    list.append( QPair<QString, QVariant>("name", PLAYER_1_NAME) );
    list.append( QPair<QString, QVariant>("display_name", PLAYER_1_DISPLAY_NAME) );

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getPlayer1Properties(const QString &fileName)
{
    QList<QPair<QString, QVariant>> list;

    QSettings sett( fileName, QSettings::IniFormat);
    sett.beginGroup("player_1");

    QPair<QString, QVariant> pair;

    foreach (const QString &childKey, sett.childKeys())
    {
        list.append( QPair<QString, QVariant>(childKey, sett.value(childKey)) );
    }

    sett.endGroup();

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getPlayer2Properties()
{
    if(!configFileName.isEmpty()) return getPlayer2Properties(configFileName);

    QList<QPair<QString, QVariant>> list;

    list.append( QPair<QString, QVariant>("name", PLAYER_2_NAME) );
    list.append( QPair<QString, QVariant>("display_name", PLAYER_2_DISPLAY_NAME) );

    return list;
}

QList<QPair<QString, QVariant> > c_MyQApplication::getPlayer2Properties(const QString &fileName)
{
    QList<QPair<QString, QVariant>> list;

    QSettings sett( fileName, QSettings::IniFormat);
    sett.beginGroup("player_2");

    QPair<QString, QVariant> pair;

    foreach (const QString &childKey, sett.childKeys())
    {
        list.append( QPair<QString, QVariant>(childKey, sett.value(childKey)) );
    }

    sett.endGroup();

    return list;
}

w_board::iconMap c_MyQApplication::getIcons() const
{
    return icons;
}

bool c_MyQApplication::notify(QObject *receiver, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(e);
        int kp = key->key();

        if(kp == Qt::Key_W || kp == Qt::Key_S || kp == Qt::Key_A || kp == Qt::Key_D || kp == Qt::Key_Up || kp == Qt::Key_Down || kp == Qt::Key_Left || kp == Qt::Key_Right )
            if(!pressedKeys.contains( static_cast<int>(key->key()) ))
                pressedKeys.append(kp);
        emit changeMoveDirectionKeysPressed(pressedKeys);
        return true;

    } else if(e->type() == QEvent::KeyRelease) {
        QKeyEvent* key = static_cast<QKeyEvent*>(e);
        int kp = key->key();
        pressedKeys.removeAll(kp);
        return true;
    }

    return QApplication::notify(receiver, e);
}

void c_MyQApplication::loadIcons()
{
    icons = new QMap<board::BoardField, QPixmap *>();

    QPixmap * pixmap = new QPixmap(":/graphs/board_empty25x25.png", "png");
    if( !pixmap->isNull() )
        (*icons)[board::EMPTY] = new QPixmap(*pixmap);
    else
        (*icons)[board::EMPTY] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/wall_50x50.png", "png");
    if( !pixmap->isNull() )
        (*icons)[board::WALL] = new QPixmap(*pixmap);
    else
        (*icons)[board::WALL] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/wall_50x50.png", "png");
    if( !pixmap->isNull() )
        (*icons)[board::WALL] = new QPixmap(*pixmap);
    else
        (*icons)[board::WALL] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/block_50x50.png", "png");
    if( !pixmap->isNull() )
        (*icons)[board::BLOCK] = new QPixmap(*pixmap);
    else
        (*icons)[board::BLOCK] = new QPixmap();
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_head_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::SNAKE_HEAD_DOWN] = new QPixmap(*pixmap);
        (*icons)[board::SNAKE_HEAD_UP] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
        (*icons)[board::SNAKE_HEAD_LEFT] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
        (*icons)[board::SNAKE_HEAD_RIGHT] = new QPixmap((*pixmap).transformed(QTransform().rotate(-90)));
    }
    else {
        (*icons)[board::SNAKE_HEAD_DOWN] = new QPixmap();
        (*icons)[board::SNAKE_HEAD_UP] = new QPixmap();
        (*icons)[board::SNAKE_HEAD_LEFT] = new QPixmap();
        (*icons)[board::SNAKE_HEAD_RIGHT] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::SNAKE_BODY_HORIZONTAL] = new QPixmap(*pixmap);
        (*icons)[board::SNAKE_BODY_VERTICAL] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
    } else {
        (*icons)[board::SNAKE_BODY_HORIZONTAL] = new QPixmap();
        (*icons)[board::SNAKE_BODY_VERTICAL] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_bend_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::SNAKE_BODY_BEND_LT] = new QPixmap(*pixmap);
        (*icons)[board::SNAKE_BODY_BEND_RB] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
    } else {
        (*icons)[board::SNAKE_BODY_BEND_LT] = new QPixmap();
        (*icons)[board::SNAKE_BODY_BEND_RB] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_body_bend_2_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::SNAKE_BODY_BEND_LB] = new QPixmap(*pixmap);
        (*icons)[board::SNAKE_BODY_BEND_RT] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
    } else {
        (*icons)[board::SNAKE_BODY_BEND_LB] = new QPixmap();
        (*icons)[board::SNAKE_BODY_BEND_RT] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/snake_tail_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::SNAKE_TAIL_RIGHT] = new QPixmap(*pixmap);
        (*icons)[board::SNAKE_TAIL_LEFT] = new QPixmap((*pixmap).transformed(QTransform().rotate(180)));
        (*icons)[board::SNAKE_TAIL_DOWN] = new QPixmap((*pixmap).transformed(QTransform().rotate(90)));
        (*icons)[board::SNAKE_TAIL_UP] = new QPixmap((*pixmap).transformed(QTransform().rotate(-90)));
    } else {
        (*icons)[board::SNAKE_TAIL_UP] = new QPixmap();
        (*icons)[board::SNAKE_TAIL_DOWN] = new QPixmap();
        (*icons)[board::SNAKE_TAIL_LEFT] = new QPixmap();
        (*icons)[board::SNAKE_TAIL_RIGHT] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/food_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::FOOD_LVL_1] = new QPixmap(*pixmap);
    } else {
        (*icons)[board::FOOD_LVL_1] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/food_x2_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::FOOD_LVL_2] = new QPixmap(*pixmap);
    } else {
        (*icons)[board::FOOD_LVL_2] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/coin_x1_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::COIN_LVL_1] = new QPixmap(*pixmap);
    } else {
        (*icons)[board::COIN_LVL_1] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/coin_x2_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::COIN_LVL_2] = new QPixmap(*pixmap);
    } else {
        (*icons)[board::COIN_LVL_2] = new QPixmap();
    }
    delete pixmap;

    pixmap = new QPixmap(":/graphs/coin_x3_50x50.png", "png");
    if( !pixmap->isNull() ) {
        (*icons)[board::COIN_LVL_3] = new QPixmap(*pixmap);
    } else {
        (*icons)[board::COIN_LVL_3] = new QPixmap();
    }
    delete pixmap;
}

void c_MyQApplication::error(const QString& message)
{
    QMessageBox::critical(nullptr, QString("Błąd uruchamiania."),
                                   QString(message),
                                   QMessageBox::Ok, QMessageBox::Ok);
}

