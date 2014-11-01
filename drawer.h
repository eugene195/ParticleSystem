#ifndef DRAWER_H
#define DRAWER_H

#include <QPointF>
#include <QGraphicsScene>
#include "emissionstorage.h"
#include <QDebug>
class Drawer
{

private:
    QGraphicsScene *scene;
public:
    Drawer(QGraphicsScene *newScene) : scene(newScene){}

    void addPartToCanvas(const ParticleVector & particles){
        foreach(Particle * part, particles){
            scene->addItem(part);
        }
    }

    void deletePartFromCanvas(ParticleVector & particles) {
        foreach(Particle * part, particles){
            scene->removeItem(part);
            delete part;
        }
    }
};
#endif // DRAWER_H
