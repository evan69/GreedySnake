#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SIZE 13
#include <QMainWindow>
#include <QToolBar>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>
#include "snake.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    
private:
    Ui::MainWindow *ui;
    QToolBar* toolbar;
    snake* mySnake;
    QPainter* painter;
    
    QAction* startAction;
    QAction* pauseAction;
    QAction* exitAction;
    
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
public slots:
    void updatePainter();
    void deathSlot();
};

#endif // MAINWINDOW_H
