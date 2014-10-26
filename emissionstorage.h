#ifndef EMISSIONSTORAGE_H
#define EMISSIONSTORAGE_H

#include "emitter.h"
#include "field.h"
#include <QList>

typedef QList<Particle *> ParticleList;

class EmissionStorage
{
public:
    EmissionStorage(Emitter * initialEmit) : emitter(initialEmit), particleList(QList<Particle *>()) {}
    EmissionStorage(MathVector emitterPos) : emitter(new Emitter(emitterPos)), particleList(QList<Particle *>()) {}
    ParticleList emitParticle();
    void moveParticles();
    void applyField(const FieldList & fields);
    int currentSize() {
        return particleList.size();
    }
    int deletionSize() {
        return partToDelete.size();
    }

    ParticleList getPartToDelete() {
        return partToDelete;
    }

    void clearDeletedParts() {
        partToDelete.clear();
    }

    void changeEmitterField(int value, QString field) {
        if (field == "emissionRate")
            emitter->changeRate(value);
        else
            emitter->changeSpread(value);
    }

private:
    Emitter * emitter;
    ParticleList particleList;
    ParticleList partToDelete;
};

typedef QList<EmissionStorage *> StorageList;

#endif // EMISSIONSTORAGE_H
