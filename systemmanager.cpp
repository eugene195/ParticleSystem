#include "systemmanager.h"



void SystemManager::loop()
{

    // Generate and add to scene
    foreach (EmissionStorage * storage, storages) {
        ParticleList newParticles = storage->emitParticle();
        drawer->addToCanvas(newParticles);
    }

    // draw
    drawer->exec();
}
