#ifndef EMISSIONMANAGER_H
#define EMISSIONMANAGER_H

#include "emissionstorage.h"
#include "drawer.h"
#include "mover.h"
#include "field.h"


class SystemManager
{
public:
//    TODO
//    static const SystemManager & Instance()
//    {
//        static SystemManager inst;
//        return inst;
//    }



    void initScene(QGraphicsScene *scene) {
        drawer = new Drawer(scene);
    }

    void addEmission(Emitter * emitter) {
        EmissionStorage * store = new EmissionStorage(emitter);
        storages.append(store);
    }

    void addField(Field * fld) {
        fields.append(fld);
    }

    SystemManager() { drawer = 0; }
public slots:
    void loop();
private:
    int maxPartPerStore;
    StorageList storages;
    FieldList fields;
    Drawer *drawer;

};

#endif // EMISSIONMANAGER_H
