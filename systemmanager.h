#ifndef EMISSIONMANAGER_H
#define EMISSIONMANAGER_H

#include "emissionstorage.h"
#include "drawer.h"

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
private:
    SystemManager() { drawer = new Drawer(); }
    StorageList storages;
    Drawer *drawer;

};

#endif // EMISSIONMANAGER_H
