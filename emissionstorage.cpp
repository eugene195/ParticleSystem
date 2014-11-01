#include "emissionstorage.h"

ParticleVector EmissionStorage::emitParticle()
{
    ParticleVector newList;
    newList = emitter->emitParticles();

    foreach (Particle * newPart, newList) {
        particleList.append(newPart);
    }
    return newList;
}

void EmissionStorage::moveParticles()
{
    int size = particleList.size();
    for (int i = 0; i < size; ++i) {
        if (particleList[i]->isAlive())
            particleList[i]->advance();
        else {
            partToDelete.append(particleList[i]);
            particleList.removeAt(i);
            --i;
            --size;
        }
    }
//    foreach(Particle * part, particleList){
//        if (part->isAlive())
//            part->advance();
//        else {
//            partToDelete.append(part);
//            particleList.removeOne(part);
//        }
//    }
}

void EmissionStorage::applyField(const FieldList &fields)
{
    foreach(Particle * part, particleList){
        part->applyField(fields);
    }
}
