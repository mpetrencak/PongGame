#include "game.h"
#include <rectangle.h>
#include <mainwindow.h>
#include <ball.h>
#include <QMainWindow>
#include <game.h>

Game::Game(QWidget *parent) : QObject(parent)
{
    this->parent = parent;
    //this->player = new Rectangle(parent,5,false);
    //this->AI =  new Rectangle(parent,parent->rect().width()-15,true);


}

void Game::NewGame()
{
    this->ball = new Ball(parent);

}



void Game::Ychanged(int position)
{

}

void Game::timerEvent(QTimerEvent *)
{

}

