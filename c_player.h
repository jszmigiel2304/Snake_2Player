#ifndef C_PLAYER_H
#define C_PLAYER_H

#include "_myData.h"

#include <QObject>
#include <QList>
#include <QPoint>
#include <QUuid>


class c_player : public QObject
{
    Q_OBJECT
public:
    explicit c_player(QObject *parent = nullptr);
    ~c_player();

    const QString &getName() const;

    void setName(const QString &newName);

public slots:

private:
    QString name;

private slots:

signals:

};

#endif // C_PLAYER_H
