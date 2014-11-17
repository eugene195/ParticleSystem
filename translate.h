#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "mathvector.h"

class Translate
{
public:
    void apply(MathVector & vec) {
        vec = vec + movementVector;
    }

    void move(int valX, int valY, int valZ = 0) {
        movementVector.X += valX;
        movementVector.Y += valY;
        movementVector.Z += valZ;
    }

private:
    MathVector movementVector;

};

#endif // TRANSLATE_H
