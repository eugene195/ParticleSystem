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
    manager.setMaximumPerStore(ui->PartPerStorage->value());
    srand (time(NULL));
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(manager::loop()));
    timer.start(1000 / 33);
}

void MainWindow::on_FieldPlacement_clicked()
{
    MathVector * position = new MathVector(ui->FieldX->value(),
                                     ui->FieldY->value(),
                                     ui->FieldZ->value());
    int mass = ui->FieldMass->value();
    Field * fld = new Field(position, mass);
    manager.addField(fld);
}

void MainWindow::on_EmitterPlacement_clicked()
{
    MathVector position = MathVector(ui->EmitterX->value(),
                                           ui->EmitterY->value(),
                                           ui->EmitterZ->value());
    MathVector speed = MathVector(ui->EmitterSpeed->value(), ui->EmitterSpeed->value(), 0);
    double spread = ui->EmitterSpread->value();
    int emissionRate = ui->EmitterRate->value();
    int acceleration = ui->EmitterAcceleration->value();
    Emitter emitter = Emitter(position, speed, spread, Qt::blue, emissionRate);
    manager.addEmission(emitter);
}
