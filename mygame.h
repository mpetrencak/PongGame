#ifndef MYGAME_H
#define MYGAME_H

#include <QObject>

class MyGame : public QObject
{
    Q_OBJECT
public:
    explicit MyGame(QObject *parent = nullptr);

signals:

};

#endif // MYGAME_H
