#ifndef C_MYQAPPLICATION_H
#define C_MYQAPPLICATION_H

#include "_myData.h"

#include <QObject>
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QPair>
#include <QVariant>
#include <QSettings>
#include <QStringView>
#include <QMessageBox>
#include <QScreen>
#include <QEvent>
#include <QKeyEvent>
#include <QSet>

class c_MyQApplication : public QApplication
{
    Q_OBJECT
public:
    explicit c_MyQApplication(int &argc, char **argv);
    ~c_MyQApplication();

    QList<QPair<QString, QVariant>> getWindowProperties();
    QList<QPair<QString, QVariant>> getWindowProperties(const QString& fileName);

    QList<QPair<QString, QVariant>> getServerProperties();
    QList<QPair<QString, QVariant>> getServerProperties(const QString& fileName);

    QList<QPair<QString, QVariant>> getPlayer1Properties();
    QList<QPair<QString, QVariant>> getPlayer1Properties(const QString& fileName);

    QList<QPair<QString, QVariant>> getPlayer2Properties();
    QList<QPair<QString, QVariant>> getPlayer2Properties(const QString& fileName);

    w_board::iconMap getIcons() const;

    bool notify(QObject *receiver, QEvent *e) override;

private:
    QString configFileName;

    w_board::iconMap icons;

    QList<int> pressedKeys;

    void loadIcons();

private slots:
    void error(const QString& message);

signals:

    void changeMoveDirectionKeysPressed(QList<int> keys);
};

#endif // C_MYQAPPLICATION_H
