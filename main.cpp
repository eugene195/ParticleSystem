#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Set a signal to emit new particles
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &w, SLOT(loop()));
    timer.start(1000 / 33);

    return a.exec();
}


// TODO
// New Scene
// Interface changes
