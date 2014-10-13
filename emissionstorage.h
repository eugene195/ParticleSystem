#ifndef EMISSIONSTORAGE_H
#define EMISSIONSTORAGE_H

#include "emitter.h"
#include "field.h"
#include <QList>

typedef QList<Particle *> ParticleList;

class EmissionStorage
{
public:
    EmissionStorage(Emitter initialEmit) : emitter(initialEmit), particleList(QList<Particle *>()) {}
    EmissionStorage(MathVector emitterPos) : emitter(Emitter(emitterPos)), particleList(QList<Particle *>()) {}
    ParticleList emitParticle();
    void moveParticles();
    void applyField(const FieldList & fields);
    int currentSize(){
        return particleList.size();
    }

private:
    Emitter emitter;
    ParticleList particleList;
};

typedef QList<EmissionStorage *> StorageList;

#endif // EMISSIONSTORAGE_H
