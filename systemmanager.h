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

    void triggerRunning() {
        running = !running;
    }

    bool isRunning() {
        return running;
    }

    void setProjectionType(ProjectionType type) {
        if (type == MATRIX)
            projector = new SceneMatrix();
        else if (type == QUATERNION)
            projector = new SceneQuaternion();
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
        if (storages.value(emission))
            storages[emission]->changeEmitterField(value, parameter);
    }

    void changeForField(int field, QString parameter, int value) {
        if (storages.value(field))
            fields[field]->changeField(parameter, value);
    }

    void reset () {
        drawer->clear();
        running = 0;
//        TODO
//        delete projector;
        foreach (EmissionStorage * st, storages) {
            delete st;
        }
        storages.clear();

        foreach (Field * fld, fields) {
            delete fld;
        }
        fields.clear();
    }

    SystemManager() {
        drawer = 0;
        running = 0;
        projector = new SceneQuaternion();
    }
public slots:
    void loop();
private:
    int maxPartPerStore;
    StorageList storages;
    FieldList fields;
    Drawer *drawer;
    bool running;

    AbstractProjector * projector;
};

#endif // EMISSIONMANAGER_H
