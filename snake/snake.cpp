#include "snake.h"
#include <QDebug>

snake::snake(int s, int initlen) : areaSize(s),timer(new QTimer())
{
    direction = rand() % 4;
    food = QPoint(rand() % areaSize,rand() % areaSize);
    QPoint head = QPoint(s/2,s/2);
    QPoint tmp = QPoint(0,0);
    for(int i = 0;i < initlen;i++)
    {
        data.push_back(head-tmp);
        tmp += transfer(direction);
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

snake::~snake()
{
    delete timer;
}

void snake::setDirection(int a)
{
    direction = a;
}

QPoint snake::transfer(int dir)
{
    if(dir == UP) return QPoint(0,-1);
    else if(dir == DOWN) return QPoint(0,1);
    else if(dir == LEFT) return QPoint(-1,0);
    else if(dir == RIGHT) return QPoint(1,0);
    else exit(-1);
}

void snake::checkDeath()
{
    bool dead = 0;
    for(int i = 1;i < data.size();i++)
    {
        if(data[i] == data[0])
        {
            dead = 1;
            qDebug() << data[0].x() << data[0].y();
            qDebug() << data[i].x() << data[i].y();
        }
    }
    if(data[0].x() < 0 || data[0].x() > areaSize-1 || data[0].y() < 0 || data[0].y() > areaSize-1)
    {
        dead = 1;
    }
    if(dead) emit deathSignal();
}

void snake::start()
{
    timer->start(500);
    emit updateSnake();
}

void snake::move()
{
    data.push_front(data[0] + transfer(direction));
    if(food == data[0])
    {
        food = QPoint(rand() % areaSize,rand() % areaSize);
    }
    else data.pop_back();
    emit updateSnake();
    checkDeath();
}

void snake::pause()
{
    timer->stop();
}
/*
void snake::death()
{
    
}
*/
