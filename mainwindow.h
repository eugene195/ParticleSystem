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

    void on_FieldPlacement_clicked();

    void on_EmitterPlacement_clicked();

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
