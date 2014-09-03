#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>

class Canvas
{
private:
    QGraphicsScene *scene;
public:
    Canvas() { scene = new QGraphicsScene(); }
    void addToCanvas(double x, double y, double z){
        scene->addEllipse(x, y, 2, 2);
    }
    void draw(){
        scene->update();
    }
};

#endif // CANVAS_H
