#include "systemmanager.h"
#include <unistd.h>

const int DELETION_TRESHOLD = 20;

void SystemManager::loop()
{
    if(running){

        auto begin = std::chrono::high_resolution_clock::now();



        Mover::move(storages, fields);
        // Generate and add to scene
        foreach (EmissionStorage * storage, storages) {
            ParticleVector newParticles = storage->emitParticle();
            drawer->addPartToCanvas(newParticles);


            ParticleVector deletedParticles = storage->getPartToDelete();
            drawer->deletePartFromCanvas(deletedParticles);
            storage->clearDeletedParts();

//            if (storage->deletionSize() > DELETION_TRESHOLD) {
//                ParticleVector deletedParticles = storage->getPartToDelete();
//                drawer->deletePartFromCanvas(deletedParticles);
//                storage->clearDeletedParts();
//            }


        }
        auto end = std::chrono::high_resolution_clock::now();
        qDebug() <<  std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
    }
}
