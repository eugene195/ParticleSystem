#include "emissionstorage.h"

void EmissionStorage::emitParticle()
{
    QList<Particle *> newList;
    newList = emitter.emitParticles();

    foreach (Particle * newPart, newList) {
        particleList.append(newPart);
    }
}
