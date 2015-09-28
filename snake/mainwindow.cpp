#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMessageBox>
#include <QDebug>

const QString imagesPath = ":/images";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    toolbar(new QToolBar(this)),
    mySnake(new snake(SIZE))
{
    ui->setupUi(this);
    this->setContextMenuPolicy(Qt::NoContextMenu);
    startAction = new QAction(QIcon(imagesPath + "/start.png"),tr("开始游戏"),this);
    pauseAction = new QAction(QIcon(imagesPath + "/pause.png"),tr("暂停游戏"),this);
    exitAction = new QAction(QIcon(imagesPath + "/exit.png"),tr("退出游戏"),this);
    toolbar->addAction(startAction);
    toolbar->addAction(pauseAction);
    toolbar->addAction(exitAction);
    this->addToolBar(Qt::TopToolBarArea,toolbar);
    connect(startAction,SIGNAL(triggered(bool)),mySnake,SLOT(start()));
    connect(pauseAction,SIGNAL(triggered(bool)),mySnake,SLOT(pause()));
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(mySnake,SIGNAL(updateSnake()),this,SLOT(update()));
    connect(mySnake,SIGNAL(deathSignal()),this,SLOT(deathSlot()));
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Up) mySnake->setDirection(UP);
    if(event->key() == Qt::Key_Down) mySnake->setDirection(DOWN);
    if(event->key() == Qt::Key_Left) mySnake->setDirection(LEFT);
    if(event->key() == Qt::Key_Right) mySnake->setDirection(RIGHT);
}

void MainWindow::paintEvent(QPaintEvent*)
{
    painter = new QPainter(this);
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawPolygon(QPolygon(QRect(QPoint(20,60),QSize(260,260))));
    painter->setPen(Qt::white);
    for(int i = 1;i < 15;i++)
    {
        painter->drawLine(QPoint(20*i,60),QPoint(20*i,320));
        painter->drawLine(QPoint(20,20*i+40),QPoint(280,20*i+40));
    }
    painter->setBrush(Qt::white);  
    for(int i = 0;i < mySnake->data.size();i++)
    {
        painter->drawPolygon(QPolygon(QRect(QPoint(mySnake->data[i].x()*20+20,mySnake->data[i].y()*20+60),QSize(20,20))));
    }
    painter->setBrush(Qt::red);
    painter->drawPolygon(QPolygon(QRect(QPoint(mySnake->food.x()*20+20,mySnake->food.y()*20+60),QSize(20,20))));
}

void MainWindow::updatePainter()
{
    update();
}

void MainWindow::deathSlot()
{
    QMessageBox::information(this,"游戏结束","游戏结束",QMessageBox::Ok);
    disconnect(startAction,SIGNAL(triggered(bool)),mySnake,SLOT(start()));
    disconnect(pauseAction,SIGNAL(triggered(bool)),mySnake,SLOT(pause()));
    disconnect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    disconnect(mySnake,SIGNAL(updateSnake()),this,SLOT(update()));
    disconnect(mySnake,SIGNAL(deathSignal()),this,SLOT(deathSlot()));
    mySnake = new snake(SIZE);
    connect(startAction,SIGNAL(triggered(bool)),mySnake,SLOT(start()));
    connect(pauseAction,SIGNAL(triggered(bool)),mySnake,SLOT(pause()));
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(mySnake,SIGNAL(updateSnake()),this,SLOT(update()));
    connect(mySnake,SIGNAL(deathSignal()),this,SLOT(deathSlot()));
    update();
}
