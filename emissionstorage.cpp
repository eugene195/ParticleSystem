#include "emissionstorage.h"

ParticleList EmissionStorage::emitParticle()
{
    ParticleList newList;
    newList = emitter.emitParticles();

    foreach (Particle * newPart, newList) {
        particleList.append(newPart);
    }
    return newList;
}

void EmissionStorage::moveParticles()
{
    foreach(Particle * part, particleList){
        part->advance();
    }
}

void EmissionStorage::applyField(const FieldList &fields)
{
    foreach(Particle * part, particleList){
        part->applyField(fields);
    }
}
