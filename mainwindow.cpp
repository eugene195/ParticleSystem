#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    NICE!
    this->setWindowState(Qt::WindowMaximized);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::black));
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
    QColor col(Qt::blue);

    Context context;
    context.add(&acceleration, "acceleration");
    context.add(&position, "position");
    context.add(&speed, "speed");
    context.add(&spread, "spread");
    context.add(&col, "color");
    context.add(&emissionRate, "emissionRate");
    context.add(&lifetime, "lifetime");
    manager.addEmission(context);


    QString positionStr = "(" + QString::number(position.X) + ", " +
                       QString::number(position.Y) + ", " +
                       QString::number(position.Z) + ")";
    ui->EmitterList->addItem("Emitter position: " + positionStr);
    ui->EmitterList->setCurrentRow(ui->EmitterList->count() - 1);
}

void MainWindow::on_EmissionRateSlider_sliderMoved(int position)
{

}

void MainWindow::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta();
    double factor = 1;
    if (numDegrees.y() < 0)
        factor = 0.7;
    else if (numDegrees.y() > 0)
        factor = 1.2;
    manager.resize(factor);
}


// Movement - ASWD
// Rotation UI, HJ, BN
void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    int valX, valY;
    valX = valY = 0;
    if (key == 65)
        valX = +10;
    else if (key == 87)
        valY = 10;
    else if (key == 68)
        valX = -10;
    else if (key == 83)
        valY = -10;
    else if (key == 85)
        manager.rotateZ(ZPOS);
    else if (key == 73)
        manager.rotateZ(ZNEG);
    else if (key == 72)
        manager.rotateY(YPOS);
    else if (key == 74)
        manager.rotateY(YNEG);
    else if (key == 66)
        manager.rotateX(XPOS);
    else if (key == 78)
        manager.rotateX(XNEG);
    manager.move(valX, valY);
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
    manager.rotateY(YPOS);
}

void MainWindow::on_rotateYNeg_clicked()
{
     manager.rotateY(YNEG);
}

void MainWindow::on_rotateXPos_clicked()
{
    manager.rotateX(XPOS);
}

void MainWindow::on_resize_plus_clicked()
{
    double factor = 1.3;
    manager.resize(factor);
}

void MainWindow::on_resize_minus_clicked()
{
    double factor = 0.7;
    manager.resize(factor);
}



void MainWindow::on_rotatorOZ_sliderMoved(int position)
{

}

void MainWindow::on_rotatorOZ_valueChanged(int value)
{
    manager.rotateZ(ZPOS);
}
