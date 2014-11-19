#include "systemmanager.h"
#include <unistd.h>

const int DELETION_TRESHOLD = 20;

void SystemManager::loop()
{
    if(running){


        Mover::move(storages, fields);
        // Generate and add to scene
        foreach (EmissionStorage * storage, storages) {
            ParticleVector newParticles = storage->emitParticle();
            drawer->addPartToCanvas(newParticles);
            if (storage->deletionSize() > DELETION_TRESHOLD) {
                ParticleVector deletedParticles = storage->getPartToDelete();
                drawer->deletePartFromCanvas(deletedParticles);
                storage->clearDeletedParts();
            }
        }
    }
}
