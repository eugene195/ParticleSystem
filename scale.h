#ifndef SCALE_H
#define SCALE_H
#include "mathvector.h"


class Scale
{

private:
    double scaleFactor;
public:
    Scale() { scaleFactor = 1; }

    void apply(MathVector & vec) {
        vec.X = vec.X * scaleFactor;
        vec.Y = vec.Y * scaleFactor;
        vec.Z = vec.Z * scaleFactor;
    }

    void setFactor(double newFactor) {scaleFactor = newFactor;}
    void addFactor(double addFactor) {scaleFactor *= addFactor;}

};

#endif // SCALE_H
