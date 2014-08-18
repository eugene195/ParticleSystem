#ifndef EMISSIONMANAGER_H
#define EMISSIONMANAGER_H

#include "emissionstorage.h"
class EmissionManager
{
public:
    static const EmissionManager & Instance()
    {
        static EmissionManager inst;
        return inst;
    }

    void loop();
private:
    EmissionManager() {}
    QList<EmissionStorage *> storages;

};

#endif // EMISSIONMANAGER_H
