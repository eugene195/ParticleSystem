#ifndef DRAWER_H
#define DRAWER_H

#include <QPointF>

#include "emissionstorage.h"
#include "canvas.h"

class Drawer
{
public:
    Drawer() { cnv = new Canvas(); }
    void addToCanvas(const ParticleList & particles);
    void exec();

private:
    Canvas *cnv;
};

#endif // DRAWER_H
