#include "mathvector.h"

MathVector::MathVector()
{
    X = Y = Z = 0;
}
double MathVector::getX() const
{
    return X;
}

void MathVector::setX(double value)
{
    X = value;
}
double MathVector::getY() const
{
    return Y;
}

void MathVector::setY(double value)
{
    Y = value;
}
double MathVector::getZ() const
{
    return Z;
}

void MathVector::setZ(double value)
{
    Z = value;
}




