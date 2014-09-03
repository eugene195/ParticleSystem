#ifndef EMISSIONSTORAGE_H
#define EMISSIONSTORAGE_H

#include "emitter.h"
#include <QList>

typedef QList<Particle *> ParticleList;

class EmissionStorage
{
public:
    EmissionStorage(Emitter initialEmit) : emitter(initialEmit), particleList(QList<Particle *>()) {}
    EmissionStorage(MathVector emitterPos) : emitter(Emitter(emitterPos)), particleList(QList<Particle *>()) {}
    ParticleList emitParticle();

private:
    Emitter emitter;
    QList<Particle *> particleList;
};

#endif // EMISSIONSTORAGE_H
