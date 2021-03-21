#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <game.h>


class Rectangle : public QObject
{
    Q_OBJECT
public:
    explicit Rectangle(QWidget *parent = nullptr, int x=0, bool AI = false);



public slots:
    void draw (QPainter &painter);
    void Ychanged(int position);
        void ballY(int Ypos);

signals:
    void sendAIPos(int YPos);


protected:
    QWidget *parent = NULL;
    QRect rct;
    int x = 0;
    int y = 0;

    bool AI = false;

    int ky = 0;

    virtual void timerEvent(QTimerEvent *);


public:
    QRect rectSize;
    QPoint rectPoit;


};

#endif // RECTANGLE_H
