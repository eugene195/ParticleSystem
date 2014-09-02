#include "emissionmanager.h"



void EmissionManager::loop()
{
    foreach (EmissionStorage * storage, storages) {
        storage->emitParticle();
    }
}
