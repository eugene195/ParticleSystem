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
    srand (time(NULL));
}

void MainWindow::on_FieldPlacement_clicked()
{
    MathVector * position = new MathVector(ui->FieldX->value(),
                                     ui->FieldY->value(),
                                     ui->FieldZ->value());
    int mass = ui->FieldMass->value();
    Field * fld = new Field(position, mass);
    manager.addField(fld);            
    QString positionStr = "(" + QString::number(position->getX()) + ", " +
                       QString::number(position->getY()) + ", " +
                       QString::number(position->getZ()) + ")";
    ui->FieldList->addItem("Field position: " + positionStr);
}

void MainWindow::on_EmitterPlacement_clicked()
{
    MathVector position = MathVector(ui->EmitterX->value(),
                                     ui->EmitterY->value(),
                                     ui->EmitterZ->value());

    MathVector speed = MathVector(ui->EmitterSpeedX->value(),
                                  ui->EmitterSpeedY->value(),
                                  ui->EmitterSpeedZ->value());

    MathVector acceleration = MathVector(ui->EmitterAccX->value(),
                                         ui->EmitterAccY->value(),
                                         ui->EmitterAccZ->value());

    double spread = ui->EmitterSpread->value();
    int emissionRate = ui->EmitterRate->value();

//    TODO CREATE EMITTERS INSIDE MANAGER
    Emitter * emitter = new Emitter(acceleration, position, speed, spread, Qt::blue, emissionRate);
    manager.addEmission(emitter);
    QString positionStr = "(" + QString::number(position.getX()) + ", " +
                       QString::number(position.getY()) + ", " +
                       QString::number(position.getZ()) + ")";
    ui->EmitterList->addItem("Emitter position: " + positionStr);
}
