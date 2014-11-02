#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <QVector>
#include <qmath.h>

class MathVector
{
public:
    MathVector();
    MathVector(double x, double y, double z){
        X = x;
        Y = y;
        Z = z;
    }

    const MathVector operator+(const MathVector& right) {
        return MathVector(
                  X + right.X
                , Y + right.Y
                , Z + right.Z );
    }

    const MathVector operator-(const MathVector& right) {
        return MathVector(
                  X - right.X
                , Y - right.Y
                , Z - right.Z );
    }


    const MathVector operator*(double number) {
        return MathVector(
                  X * number
                , Y * number
                , Z * number );
    }

    double operator*(const MathVector& right){
        return    X * right.X
                + Y * right.Y
                + Z * right.Z;
    }

    bool operator ==(const MathVector & right){
        return ((X == right.X) && (Y == right.Y) && (Z == right.Z));
    }

    bool operator !=(const MathVector & right){
        return (!(*this == right));
    }

    double getLen(){
        return sqrt(X*X + Y*Y + Z*Z);
    }

    MathVector getAngle(){
        return MathVector(atan2(Y, X), atan2(Z, Y), atan2(Z, X));
    }

    static MathVector fromAngle(const MathVector & angle, double length){
        return MathVector(length * cos(angle.X), length * sin(angle.X), length * sin(angle.Z));
    }

    double X, Y, Z;



};

#endif // MATHVECTOR_H
