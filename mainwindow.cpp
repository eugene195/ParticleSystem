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

void MainWindow::on_FieldPlacement_2_clicked()
{
    MathVector * position = new MathVector(ui->FieldX->value(),
                                     ui->FieldY->value(),
                                     ui->FieldZ->value());
    int mass = ui->FieldMass_2->value();
    Field * fld = new Field(position, mass);
    manager.addField(fld);
    QString positionStr = "(" + QString::number(position->X) + ", " +
                       QString::number(position->Y) + ", " +
                       QString::number(position->Z) + ")";
    ui->FieldList->addItem("Field position: " + positionStr);
    ui->FieldList->setCurrentRow(ui->FieldList->count() - 1);
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
    int lifetime = ui->EmitterLifetime->value();
//    TODO CREATE EMITTERS INSIDE MANAGER


    manager.addEmission(acceleration, position, speed, spread, Qt::blue, emissionRate, lifetime);


    QString positionStr = "(" + QString::number(position.X) + ", " +
                       QString::number(position.Y) + ", " +
                       QString::number(position.Z) + ")";
    ui->EmitterList->addItem("Emitter position: " + positionStr);
    ui->EmitterList->setCurrentRow(ui->EmitterList->count() - 1);
}

void MainWindow::on_EmissionRateSlider_sliderMoved(int position)
{

}


//Exception here
void MainWindow::on_EmissionRateSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    manager.changeForEmission(emitNum, "emissionRate", value);
}

void MainWindow::on_EmissionSpreadSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    manager.changeForEmission(emitNum, "spread", value);
}

void MainWindow::on_FieldPowerSlider_valueChanged(int value)
{
    int fieldNum = ui->FieldList->currentRow();
    manager.changeForField(fieldNum, "power", value);
}

void MainWindow::on_EmitterLifetimeSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    manager.changeForEmission(emitNum, "lifetime", value);
}

void MainWindow::on_rotateZPos_clicked()
{
    manager.rotateZ(ZPOS);
}

void MainWindow::on_rotateZNeg_clicked()
{
    manager.rotateZ(ZNEG);
}

void MainWindow::on_rotateYPos_clicked()
{
    manager.ratateY(YPOS);
}

void MainWindow::on_rotateXPos_clicked()
{
    manager.rotateX(XPOS);
}
