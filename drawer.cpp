#include "drawer.h"

void Drawer::addToCanvas(const ParticleList &particles)
{
    foreach (Particle * part, particles) {
        cnv->addToCanvas(part->getX(), part->getY(), part->getZ());
    }
}

void Drawer::exec()
{
    // У Particle есть свой paint. Что это значит? Как рисовать точки?
    cnv->draw();
}
