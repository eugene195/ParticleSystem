#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "systemmanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
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
