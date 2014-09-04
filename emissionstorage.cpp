#include "emissionstorage.h"

ParticleList EmissionStorage::emitParticle()
{
    QList<Particle *> newList;
    newList = emitter.emitParticles();

    foreach (Particle * newPart, newList) {
        particleList.append(newPart);
    }
    return newList;
}

void EmissionStorage::moveParticle()
{
    foreach(Particle * part, particleList){
        part->step();
    }
}
