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

    void addEmission(MathVector & acceleration, MathVector & position, MathVector & speed, double spread, QColor color, int rate, int lifetime) {
        Emitter * emitter = new Emitter(acceleration, position, matrix, speed, spread, color, rate, lifetime);
        EmissionStorage * store = new EmissionStorage(emitter);
        storages.append(store);
    }

    void addField(Field * fld) {
        fields.append(fld);
    }

    void resize(double factor) {
        matrix->resize(factor);
    }

    void move(int mvX, int mvY) {
        matrix->move(mvX, mvY);
    }

    void ratateY(RotateDirection direct) {
        if (direct == YPOS)
            matrix->rotateYPos();
        else if (direct == YNEG)
            matrix->rotateYNeg();
    }

    void rotateX(RotateDirection direct) {
        if (direct == XPOS)
            matrix->rotateXPos();
        else if (direct == XNEG)
            matrix->rotateXNeg();
    }

    void rotateZ(RotateDirection direct) {
        if (direct == ZPOS)
            matrix->rotateZPos();
        else if (direct == ZNEG)
            matrix->rotateZNeg();
    }

    void changeForEmission(int emission, QString parameter, int value) {
        storages[emission]->changeEmitterField(value, parameter);
    }

    void changeForField(int field, QString parameter, int value) {
        fields[field]->changeField(parameter, value);
    }

    SystemManager() { drawer = 0; matrix = new SceneMatrix(); }
public slots:
    void loop();
private:
    int maxPartPerStore;
    StorageList storages;
    FieldList fields;
    Drawer *drawer;
    SceneMatrix * matrix;

    Quaternion quaternion;
//    SceneMatrix matrix;
    Scale scale;
};

#endif // EMISSIONMANAGER_H
