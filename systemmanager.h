#ifndef EMISSIONMANAGER_H
#define EMISSIONMANAGER_H

#include "emissionstorage.h"
#include "drawer.h"
#include "mover.h"
#include "field.h"
#include "Projectors/scenequaternion.h"
#include "scenematrix.h"


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

    void addEmission(Context & context) {
        context.add(projector, QString("projector"));
        Emitter * emitter = new Emitter(context);
        EmissionStorage * store = new EmissionStorage(emitter);
        storages.append(store);
    }

    void addField(Field * fld) {
        fields.append(fld);
    }

    void resize(double factor) {
        projector->resize(factor);
    }

    void move(int mvX, int mvY) {
        projector->addMovement(mvX, mvY);
    }

    void rotateY(RotateDirection direct) {
        if (direct == YPOS)
            projector->rotateYPos();
        else if (direct == YNEG)
            projector->rotateYNeg();
    }

    void rotateX(RotateDirection direct) {
        if (direct == XPOS)
            projector->rotateXPos();
        else if (direct == XNEG)
            projector->rotateXNeg();
    }

    void rotateZ(RotateDirection direct) {
        if (direct == ZPOS)
            projector->rotateZPos();
        else
            projector->rotateZNeg();
    }

    void changeForEmission(int emission, QString parameter, int value) {
        storages[emission]->changeEmitterField(value, parameter);
    }

    void changeForField(int field, QString parameter, int value) {
        fields[field]->changeField(parameter, value);
    }

    SystemManager() {
        drawer = 0;

        // TODO
        projector = new SceneQuaternion();
//        projector = new SceneMatrix();
    }
public slots:
    void loop();
private:
    int maxPartPerStore;
    StorageList storages;
    FieldList fields;
    Drawer *drawer;

    AbstractProjector * projector;
};

#endif // EMISSIONMANAGER_H
