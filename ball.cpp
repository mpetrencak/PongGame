#include "ball.h"
#include <QTimer>

Ball::Ball(QWidget *parent) : QObject(parent)
{
    active = true;
    this->parent = parent;
    QRect rec = this->parent->rect();

    x= rec.center().x();
    y =rec.center().y();


    ky = -4;
    kx = 4;


    timer = startTimer(10);



}

void Ball::draw(QPainter &painter)
{
    painter.drawEllipse(x,y,30,30);
    emit ballY(y);
}


//getting player position
void Ball::Ychanged(int position)
{
    this->yMouse = position;

}


//getting ai position
void Ball::sendAIPos(int YPos)
{
    this->yAI = YPos;

}

void Ball::stpTimer()
{

    killTimer(timer);
}

void Ball::rsmTimer()
{
    timer = startTimer(10);


}

void Ball::timerEvent(QTimerEvent *)
{
    QRect rct = parent->rect();

    if(x<5)
    {
        emit goolAI();
        y = rct.center().y();
        x = rct.center().x();
        ky = -4;
        kx = 4;
    }
    if(x>rct.width()-5)
    {
        emit goolPlayer();
        y = rct.center().y();
        x = rct.center().x();
        ky = -4;
        kx = 4;
    }


    if( yAI == y && x< rct.width()-30 && x> rct.width()-50)
    {
        kx *= - 1;
    }

    if((yMouse-y) >= -70 && (yMouse-y <= 50) && x >= 29 && x <35)
    {
        kx *= -1;
        ky *= -1;
    }

    if(y <= 20 || y >= rct.height()-30)
    {
        ky *= -1;
    }

    x += kx;
    y += ky;

    parent->update();



}


