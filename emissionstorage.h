#ifndef EMISSIONSTORAGE_H
#define EMISSIONSTORAGE_H

#include "emitter.h"
#include "field.h"
#include <QList>

#include "scale.h"


class EmissionStorage
{
public:
    EmissionStorage(Emitter * initialEmit) : emitter(initialEmit), particleList(ParticleVector()) {}
    ~EmissionStorage() {
        delete emitter;
    }

    ParticleVector emitParticle();
    void moveParticles();
    void applyField(const FieldList & fields);
    int currentSize() {
        return particleList.size();
    }
    int deletionSize() {
        return partToDelete.size();
    }

    ParticleVector getPartToDelete() {
        return partToDelete;
    }

    void clearDeletedParts() {
        partToDelete.clear();
    }

    void changeEmitterField(int value, QString field) {
        if (field == "emissionRate")
            emitter->changeRate(value);
        else if (field == "spread")
            emitter->changeSpread(value);
        else
            emitter->changeLifetime(value);
    }

    void changeColor(int red, int green, int blue, int transparency) {
        emitter->changeColor(red, green, blue, transparency);
    }

private:
    Emitter * emitter;
    ParticleVector particleList;
    ParticleVector partToDelete;
};

typedef QList<EmissionStorage *> StorageList;

#endif // EMISSIONSTORAGE_H
