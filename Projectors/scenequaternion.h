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
        quaternion = quaternion * zNegativeQuat;
    }

    void rotateZNeg() {
        quaternion = quaternion * zPositiveQuat;
    }

    void rotateYPos() {
        quaternion = quaternion * yPositiveQuat;
    }

    void rotateYNeg() {
        quaternion = quaternion * yNegativeQuat;
    }

    void rotateXPos() {
        quaternion = quaternion * xPositiveQuat;
    }

    void rotateXNeg() {
        quaternion = quaternion * xNegativeQuat;
    }

//    **********************************************

    void resize(double factor) {
        scale.addFactor(factor);
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
    const double angle = M_PI / 180;

    void adjustQuaternions() {
        xPositiveQuat.fromAxisAngle(MathVector(1, 0, 0), angle);
        xNegativeQuat.fromAxisAngle(MathVector(1, 0, 0), -angle);

        yPositiveQuat.fromAxisAngle(MathVector(0, 1, 0), angle);
        yNegativeQuat.fromAxisAngle(MathVector(0, 1, 0), -angle);

        zPositiveQuat.fromAxisAngle(MathVector(0, 0, 1), angle);
        zNegativeQuat.fromAxisAngle(MathVector(0, 0, 1), -angle);
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
