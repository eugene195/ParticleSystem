#ifndef DRAWER_H
#define DRAWER_H

#include <QPointF>
#include <QGraphicsScene>
#include "emissionstorage.h"

class Drawer
{

private:
    QGraphicsScene *scene;
public:
    Drawer(QGraphicsScene *newScene) { scene = newScene;}

    void addPartToCanvas(const ParticleList & particles){
        foreach(Particle * part, particles){
            scene->addItem(part);
        }
    }

    void exec(){
        scene->advance();
        scene->update();
    }
};
#endif // DRAWER_H
