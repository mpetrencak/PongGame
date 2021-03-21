#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <rectangle.h>
#include <game.h>
#include <ball.h>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    //ui->statusbar->showMessage("Score");

    ui->setupUi(this);

    this->setMouseTracking(true);

    player = new Rectangle(this,20,false);
    AI = new Rectangle(this,this->rect().width()-30,true);









    connect(this,&MainWindow::draw,AI,&Rectangle::draw);
    connect(this,&MainWindow::draw,player,&Rectangle::draw);
    connect(this,&MainWindow::Ychanged,player,&Rectangle::Ychanged);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(),QBrush(QColor(Qt::black)));

    painter.setPen(Qt::red);


    painter.drawRect(rect().x(),rect().y()+ui->menubar->height(),rect().width()-1,rect().height()-22);
    painter.drawLine(rect().width()/2,0,rect().width()/2,rect().height());
    for (int i = 0; i < 3; i++)
    {
        painter.drawLine((rect().width()/2)+i,0,(rect().width()/2)+i,rect().height());
        painter.drawLine((rect().width()/2)-i,0,(rect().width()/2)-i,rect().height());

    }



    painter.setBrush(QBrush(QColor(Qt::white)));

    emit draw(painter);



}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    emit Ychanged(event->y());



}

void MainWindow::goolPlayer()
{





    PlayerScore++;


    QMessageBox msgBox;
    msgBox.setText("Score is " +QString::number(PlayerScore)+" - " +QString::number(AIScore));
    msgBox.exec();


}

void MainWindow::goolAI()
{
    AIScore++;


    QMessageBox msgBox;
    msgBox.setText("Score is " +QString::number(PlayerScore)+" - " +QString::number(AIScore));
    msgBox.exec();


}

void MainWindow::on_actionNew_game_triggered()
{
    if(start == false)
    {

        myBall = new Ball(this);
        start = true;



        connect(myBall,&Ball::goolAI,this,&MainWindow::goolAI);
        connect(myBall,&Ball::goolPlayer,this,&MainWindow::goolPlayer);

        connect(this,&MainWindow::stpTimer,myBall,&Ball::stpTimer);
        connect(this,&MainWindow::rsmTimer,myBall,&Ball::rsmTimer);
        connect(this,&MainWindow::Ychanged,myBall,&Ball::Ychanged);
        connect(AI,&Rectangle::sendAIPos,myBall,&Ball::sendAIPos);
        connect(myBall,&Ball::ballY,AI,&Rectangle::ballY);
        connect(this,&MainWindow::draw,myBall,&Ball::draw);

    }






}















MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_actionPause_game_triggered()
{
    if(myBall->active)
    {
        emit stpTimer();
        myBall->active = false;

    }

}

void MainWindow::on_actionresume_game_triggered()
{
    if(!myBall->active)
    {
            emit rsmTimer();
        myBall->active = true;
    }


}
