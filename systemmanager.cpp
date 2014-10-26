#include "systemmanager.h"
#include <unistd.h>

const int DELETION_TRESHOLD = 20;

void SystemManager::loop()
{
    if(drawer){
        if(storages.isEmpty())
            return;

        Mover::move(storages, fields);
        // Generate and add to scene
        foreach (EmissionStorage * storage, storages) {
            ParticleList newParticles = storage->emitParticle();
            drawer->addPartToCanvas(newParticles);
            if (storage->deletionSize() > DELETION_TRESHOLD) {
                ParticleList deletedParticles = storage->getPartToDelete();
                drawer->deletePartFromCanvas(deletedParticles);
                storage->clearDeletedParts();
            }
        }
    }
}
