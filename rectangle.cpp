#include "rectangle.h"
#include <game.h>

Rectangle::Rectangle(QWidget *parent,int x, bool AI) : QObject(parent)
{
    this->parent = parent;
    this->rct = parent->rect();

    this->x = x;
    this->y = rct.height()/2;


    this->AI = AI;
    this->ky = 1;

    startTimer(10);


}

void Rectangle::draw(QPainter &painter)
{

    painter.drawRect(x,y,10,50);
    emit sendAIPos(y);


}

void Rectangle::Ychanged(int position)
{
    y = position;

}

void Rectangle::ballY(int Ypos)
{
    y = Ypos;

}


void Rectangle::timerEvent(QTimerEvent *)
{
    {


        parent->update();
    }

}

