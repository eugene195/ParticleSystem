#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    manager.initScene(scene);
    manager.testFill();
    srand (time(NULL));
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(loop()));
//    manager.loop();
    timer.start(1000 / 33);


}
