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

void c_MyQApplication::error(const QString& message)
{
    QMessageBox::critical(nullptr, QString("Błąd uruchamiania."),
                                   QString(message),
                                   QMessageBox::Ok, QMessageBox::Ok);
}

