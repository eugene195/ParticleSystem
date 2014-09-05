#include "systemmanager.h"
#include <unistd.h>


void SystemManager::loop()
{
    if(storages.isEmpty())
        return;


    Mover::move(storages, fields);
    // Generate and add to scene
    foreach (EmissionStorage * storage, storages) {

        ParticleList newParticles = storage->emitParticle();
        drawer->addPartToCanvas(newParticles);
    }

    // draw
    drawer->exec();
}
