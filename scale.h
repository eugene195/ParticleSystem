#ifndef SCALE_H
#define SCALE_H
#include "mathvector.h"


class Scale
{
public:
    static MathVector project(const MathVector & vec) {
        return MathVector(vec.X * scaleFactor, vec.Y * scaleFactor, vec.Z * scaleFactor);
    }

    static void setFactor(double newFactor) {scaleFactor = newFactor;}
    static void addFactor(double addFactor) {scaleFactor *= addFactor;}
private:
    static double scaleFactor;
};

#endif // SCALE_H
