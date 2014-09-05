#ifndef MOVER_H
#define MOVER_H

#include "emissionstorage.h"
#include "field.h"
class Mover
{
public:
    Mover();
    static void move(StorageList & storages, const FieldList & fields){
        foreach(EmissionStorage * storage, storages){
            storage->applyField(fields);
            storage->moveParticles();
        }
    }
};

#endif // MOVER_H
