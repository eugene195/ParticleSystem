#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "../mathvector.h"

enum RotateDirection { XPOS, XNEG, YPOS, YNEG, ZPOS, ZNEG };
enum MovementDirection { MVLEFT = 16777234, MVUP, MVRIGHT, MVDOWN };
enum ProjectionType { MATRIX, QUATERNION };

class AbstractProjector
{
public:
    AbstractProjector() {}
    virtual MathVector project(const MathVector & vec) = 0;
    virtual void rotateZPos() = 0;
    virtual void rotateZNeg() = 0;
    virtual void rotateYPos() = 0;
    virtual void rotateYNeg() = 0;
    virtual void rotateXPos() = 0;
    virtual void rotateXNeg() = 0;

    virtual void addMovement(int valX, int valY, int valZ = 0) = 0;
    virtual void resize(double factor) = 0;
};

#endif // PROJECTOR_H
