#ifndef MOVER_H
#define MOVER_H

#include "emissionstorage.h"
class Mover
{
public:
    Mover();
    static void move(EmissionStorage * storage){
        storage->moveParticle();
    }
};

#endif // MOVER_H
