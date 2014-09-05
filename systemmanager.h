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



    void initScene(QGraphicsScene *scene){
        drawer = new Drawer(scene);
    }

    void testFill(){
        EmissionStorage * st = new EmissionStorage(MathVector(100, 100, 100));
        storages.append(st);
        Field *fld = new Field(new MathVector(200, 150, 0));
        fields.append(fld);
    }

    SystemManager() {  }
public slots:
    void loop();
private:

    StorageList storages;
    FieldList fields;
    Drawer *drawer;

};

#endif // EMISSIONMANAGER_H
