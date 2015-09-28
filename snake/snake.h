#ifndef SNAKE
#define SNAKE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#include <QObject>
#include <QTimer>
#include <QVector>
#include <QPoint>
#include <QChar>
#include <cstdio>

class snake : public QObject
{
    Q_OBJECT
public:
    snake(int s,int initlen = 3);
    ~snake();
    QVector<QPoint> data;
    QPoint food;
    
    void setDirection(int);
private:
    int areaSize;//游戏区大小
    int direction;
    QTimer* timer;
    
    QPoint transfer(int);
    void checkDeath();
public slots:
    void start();
    void move();
    void pause();
    
signals:
    void deathSignal();
    void updateSnake();
};

#endif // SNAKE

