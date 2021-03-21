#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <ball.h>
#include <rectangle.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);

    void NewGame();
    //Rectangle *player;
    //Rectangle *AI;


    //Ball *ball;


public slots:
    void Ychanged(int position);






signals:


protected:
    QWidget *parent = NULL;
    virtual void timerEvent(QTimerEvent *);





};

#endif // GAME_H
