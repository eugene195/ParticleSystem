#ifndef SCENEQUATERNION_H
#define SCENEQUATERNION_H

#include "../quaternion.h"
#include "../scale.h"
#include "../translate.h"

class SceneQuaternion : public AbstractProjector
{
public:
    SceneQuaternion() {
        adjustQuaternions();
    }

//    **********************************************

    void rotateZPos() {
        quaternion = quaternion * xPositiveQuat;
    }

    void rotateZNeg() {
        quaternion = quaternion * xNegativeQuat;
    }

    void rotateYPos() {
        quaternion = quaternion * yPositiveQuat;
    }

    void rotateYNeg() {
        quaternion = quaternion * yNegativeQuat;
    }

    void rotateXPos() {
        quaternion = quaternion * zPositiveQuat;
    }

    void rotateXNeg() {
        quaternion = quaternion * zNegativeQuat;
    }

//    **********************************************

    void resize(double factor) {
        scale.setFactor(factor);
    }

//    **********************************************

    void addMovement(int valX, int valY, int valZ = 0) {
        translate.move(valX, valY, valZ);
    }

//    **********************************************
    MathVector project(const MathVector & pt) {
        MathVector newVec = quaternion.project(pt);
        scale.apply(newVec);
        translate.apply(newVec);
        return newVec;
    }

private:
    void adjustQuaternions() {
        xPositiveQuat.set(Quaternion(MathVector(1, 0, 0), M_PI / 40));
        xNegativeQuat.set(Quaternion(MathVector(1, 0, 0), -M_PI / 40));

        yPositiveQuat.set(Quaternion(MathVector(0, 1, 0), M_PI / 40));
        yNegativeQuat.set(Quaternion(MathVector(0, 1, 0), -M_PI / 40));

        zPositiveQuat.set(Quaternion(MathVector(0, 0, 1), M_PI / 40));
        zNegativeQuat.set(Quaternion(MathVector(0, 0, 1), -M_PI / 40));
    }

    Quaternion quaternion;
    Scale scale;
    Translate translate;


    Quaternion xPositiveQuat;
    Quaternion xNegativeQuat;

    Quaternion yPositiveQuat;
    Quaternion yNegativeQuat;

    Quaternion zPositiveQuat;
    Quaternion zNegativeQuat;
};

#endif // SCENEQUATERNION_H
