#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QWheelEvent>
#include <QColor>
#include "systemmanager.h"
#include "context.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)

public:
    explicit MainWindow(QWidget *parent = 0);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void resetAll();
    ~MainWindow();

    QColor color() const
    {
        return m_color;
    }

private slots:
    void on_pushButton_clicked();

    void on_FieldPlacement_2_clicked();

    void on_EmitterPlacement_clicked();

    void on_EmissionRateSlider_valueChanged(int value);

    void on_EmissionSpreadSlider_valueChanged(int value);

    void on_FieldPowerSlider_valueChanged(int value);

    void on_EmitterLifetimeSlider_valueChanged(int value);

    void on_resize_plus_clicked();

    void on_resize_minus_clicked();

    void on_rotatorOZ_valueChanged(int value);

    void on_rotateClockwise_clicked();

    void on_rotateCounterClockwise_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_ShowHideMenu_clicked();

    void on_resetBtn_clicked();

    void on_action_6_triggered();

    void on_action_5_triggered();

    void onColorChanged();

public slots:
    void loop()
    {
        manager.loop();
    }

signals:
    void colorChanged(QColor arg);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SystemManager manager;
    QColor m_color;
};

#endif // MAINWINDOW_H
