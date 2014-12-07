#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowState(Qt::WindowMaximized);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::black));

    srand (time(NULL));
//    int i = rand() % 7;
//    char str[10];
//    itoa(i, str, 10);
//    scene->addPixmap(QPixmap(qApp->applicationDirPath() + "/" + str + ".jpg"));

    manager.initScene(scene);
    ui->setupUi(this);
    connect(ui->redColorSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->blueColorSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->greenColorSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    manager.triggerRunning();
    if (manager.isRunning())
        ui->pushButton->setText("Пауза");
    else
        ui->pushButton->setText("Возобновить");
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
    QColor col(Qt::white);

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

void MainWindow::resetAll()
{
    ui->EmitterList->clear();
    ui->FieldList->clear();
    manager.reset();
    ui->pushButton->setText("Возобновить");
}

void MainWindow::on_EmissionRateSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    if (emitNum >= 0)
        manager.changeForEmission(emitNum, "emissionRate", value);
}

void MainWindow::on_EmissionSpreadSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    if (emitNum >= 0)
        manager.changeForEmission(emitNum, "spread", value);
}

void MainWindow::on_FieldPowerSlider_valueChanged(int value)
{
    int fieldNum = ui->FieldList->currentRow();
    if (fieldNum >= 0)
        manager.changeForField(fieldNum, "power", value);
}

void MainWindow::on_EmitterLifetimeSlider_valueChanged(int value)
{
    int emitNum = ui->EmitterList->currentRow();
    if (emitNum >= 0)
        manager.changeForEmission(emitNum, "lifetime", value);
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

void MainWindow::on_rotatorOZ_valueChanged(int value)
{
    if (ui->XAxis->isChecked())
        manager.rotateX(XPOS);
    else if (ui->YAxis->isChecked())
        manager.rotateY(YPOS);
    else
        manager.rotateZ(ZPOS);
}

void MainWindow::on_rotateClockwise_clicked()
{
    if (ui->XAxis->isChecked())
        manager.rotateX(XPOS);
    else if (ui->YAxis->isChecked())
        manager.rotateY(YPOS);
    else
        manager.rotateZ(ZPOS);
}

void MainWindow::on_rotateCounterClockwise_clicked()
{
    if (ui->XAxis->isChecked())
        manager.rotateX(XNEG);
    else if (ui->YAxis->isChecked())
        manager.rotateY(YNEG);
    else
        manager.rotateZ(ZNEG);
}

void MainWindow::on_action_triggered()
{
    ui->splitter->show();
}

void MainWindow::on_action_2_triggered()
{
    ui->splitter->hide();
}

void MainWindow::on_ShowHideMenu_clicked()
{
    if (ui->ShowHideMenu->text() == "Спрятать") {
        ui->splitter->hide();
        ui->ShowHideMenu->setText("Показать");
    }
    else {
        ui->splitter->show();
        ui->ShowHideMenu->setText("Спрятать");
    }
}


void MainWindow::on_resetBtn_clicked()
{
    this->resetAll();
}

void MainWindow::on_action_6_triggered()
{
    this->resetAll();
    manager.setProjectionType(QUATERNION);
}

void MainWindow::on_action_5_triggered()
{
    this->resetAll();
    manager.setProjectionType(MATRIX);
}

void MainWindow::onColorChanged()
{
    m_color.setRgb(ui->redColorSlider->value(), ui->greenColorSlider->value(), ui->blueColorSlider->value());
    QPalette pal = ui->widget->palette();
    pal.setColor(QPalette::Window, m_color);
    ui->widget->setPalette(pal);
    emit colorChanged(m_color);
    int emitNum = ui->EmitterList->currentRow();
    if (emitNum >= 0)
        manager.changeColorForEmission(emitNum, ui->redColorSlider->value()
                                       , ui->greenColorSlider->value()
                                       , ui->blueColorSlider->value(), 255);
}
