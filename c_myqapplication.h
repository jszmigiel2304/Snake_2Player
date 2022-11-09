#ifndef C_MYQAPPLICATION_H
#define C_MYQAPPLICATION_H

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

class c_MyQApplication : public QApplication
{
    Q_OBJECT
public:
    explicit c_MyQApplication(int &argc, char **argv);

    QList<QPair<QString, QVariant>> getWindowProperties();
    QList<QPair<QString, QVariant>> getWindowProperties(const QString& fileName);

    QList<QPair<QString, QVariant>> getServerProperties();
    QList<QPair<QString, QVariant>> getServerProperties(const QString& fileName);

    QList<QPair<QString, QVariant>> getPlayer1Properties();
    QList<QPair<QString, QVariant>> getPlayer1Properties(const QString& fileName);

    QList<QPair<QString, QVariant>> getPlayer2Properties();
    QList<QPair<QString, QVariant>> getPlayer2Properties(const QString& fileName);

private:
    QString stylesheetFileName;
    QString configFileName;


private slots:
    void error(const QString& message);
};

#endif // C_MYQAPPLICATION_H
