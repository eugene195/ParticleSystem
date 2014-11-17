#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QWheelEvent>
#include "systemmanager.h"
#include "context.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_FieldPlacement_2_clicked();

    void on_EmitterPlacement_clicked();

    void on_EmissionRateSlider_sliderMoved(int position);

    void on_EmissionRateSlider_valueChanged(int value);

    void on_EmissionSpreadSlider_valueChanged(int value);

    void on_FieldPowerSlider_valueChanged(int value);

    void on_EmitterLifetimeSlider_valueChanged(int value);

    void on_rotateZPos_clicked();

    void on_rotateZNeg_clicked();

    void on_rotateYPos_clicked();

    void on_rotateXPos_clicked();

    void on_resize_plus_clicked();

    void on_resize_minus_clicked();

    void on_rotateYNeg_clicked();

    void on_rotatorOZ_sliderMoved(int position);

    void on_rotatorOZ_valueChanged(int value);

public slots:
    void loop()
    {
        manager.loop();
    }

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SystemManager manager;
};

#endif // MAINWINDOW_H
