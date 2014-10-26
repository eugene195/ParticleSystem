#include "emissionstorage.h"

ParticleList EmissionStorage::emitParticle()
{
    ParticleList newList;
    newList = emitter->emitParticles();

    foreach (Particle * newPart, newList) {
        particleList.append(newPart);
    }
    return newList;
}

void EmissionStorage::moveParticles()
{
    foreach(Particle * part, particleList){
        if (part->isAlive())
            part->advance();
        else {
            partToDelete.append(part);
            particleList.removeOne(part);
        }
    }
}

void EmissionStorage::applyField(const FieldList &fields)
{
    foreach(Particle * part, particleList){
        part->applyField(fields);
    }
}
