#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <ball.h>
#include <rectangle.h>
#include <game.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Game *game;
    //void WhoWin();

protected:


    virtual void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent * event);

    Rectangle *player;
    Rectangle *AI;

    Ball *myBall;

    bool start = false;


    int AIScore = 0;
    int PlayerScore =0;

public slots:
    void goolPlayer();
    void goolAI();





signals:
    void draw(QPainter &painter);
    void Ychanged(int position);
    void stpTimer();
    void rsmTimer();


private slots:
    void on_actionNew_game_triggered();



    void on_actionPause_game_triggered();

    void on_actionresume_game_triggered();

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
