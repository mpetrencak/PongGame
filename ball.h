#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>

class Ball :  public QObject
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);
    bool active = false;



public slots:
    void draw (QPainter &painter);
        void Ychanged(int position);
        void sendAIPos(int YPos);
        void stpTimer();
        void rsmTimer();


signals:
        void ballY(int YPos);
        void goolPlayer();
        void goolAI();

protected:
    QWidget *parent = NULL;
    int x = 0;
    int y = 0;

    int ky = 0;
    int kx = 0;

    int yMouse =0;

    int yAI =0;

    int minus = 0;

    int timer =0;




    virtual void timerEvent(QTimerEvent *);


};

#endif // BALL_H
