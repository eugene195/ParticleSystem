#ifndef EMISSIONSTORAGE_H
#define EMISSIONSTORAGE_H

#include "emitter.h"
#include <QList>

class EmissionStorage
{
public:
    EmissionStorage(Emitter initialEmit) : emitter(initialEmit), particleList(QList<Particle *>()) {}
    EmissionStorage(QVector3D emitterPos) : emitter(Emitter(emitterPos)), particleList(QList<Particle *>()) {}
    void emitParticle();

private:
    Emitter emitter;
    QList<Particle *> particleList;
};

#endif // EMISSIONSTORAGE_H
