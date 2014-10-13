#include "systemmanager.h"
#include <unistd.h>


void SystemManager::loop()
{
    if(drawer){
        if(storages.isEmpty())
            return;

        Mover::move(storages, fields);
        // Generate and add to scene
        foreach (EmissionStorage * storage, storages) {
            if(storage->currentSize() < maxPartPerStore){
                ParticleList newParticles = storage->emitParticle();
                drawer->addPartToCanvas(newParticles);
            }
        }

        drawer->exec();
    }
}
