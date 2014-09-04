#include "systemmanager.h"



void SystemManager::loop()
{
    while(1){
        // Generate and add to scene
        foreach (EmissionStorage * storage, storages) {
            Mover::move(storage);
            ParticleList newParticles = storage->emitParticle();
            drawer->addPartToCanvas(newParticles);
        }

        // draw
        drawer->exec();
    }
}
