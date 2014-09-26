#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &w, SLOT(loop()));
//    manager.loop();
    timer.start(1000 / 33);

    return a.exec();
}


// TODO
// Particle destroyer
// New Scene
