#ifndef EMISSIONMANAGER_H
#define EMISSIONMANAGER_H

#include "emissionstorage.h"
#include "drawer.h"
#include "mover.h"

typedef QList<EmissionStorage *> StorageList;

class SystemManager
{
public:
    static const SystemManager & Instance()
    {
        static SystemManager inst;
        return inst;
    }

    void loop();

    void initScene(QGraphicsScene *scene){
        drawer = new Drawer(scene);
    }

    void testFill(){
        EmissionStorage * st = new EmissionStorage(MathVector(100, 100, 100));
        storages.append(st);
    }

private:
    SystemManager() {  }
    StorageList storages;
    Drawer *drawer;

};

#endif // EMISSIONMANAGER_H
