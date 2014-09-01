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
        // TODO
    }

    static MathVector fromAngle(const MathVector & angle, double length){
        // TODO
    }

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

    double getZ() const;
    void setZ(double value);

private:
    double X, Y, Z;



};

#endif // MATHVECTOR_H
