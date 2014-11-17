#ifndef QUATERNION_H
#define QUATERNION_H
#include "mathvector.h"
#include "Projectors/projector.h"
class Quaternion
{
public:
    double X, Y, Z, W;

    Quaternion() {
        W = 1; X = 0; Y = 0; Z = 0;
    }

    Quaternion(double w, double x, double y, double z)
    {
        W = w; X = x; Y = y; Z = z;
    }

    Quaternion(const MathVector & vec, double w)
    {
        W = w; X = vec.X; Y = vec.Y; Z = vec.Z;
    }

    void normalise()
    {
        double magnitude = W * W + X * X + Y * Y + Z * Z;
        if (magnitude > 0.001) {
            magnitude = sqrt(magnitude);
            W /= magnitude;
            X /= magnitude;
            Y /= magnitude;
            Z /= magnitude;
        }
        else {
            W = 1; X = 0; Y = 0; Z = 0;
        }
    }

    void conjugate()
    {
        X = -X; Y = -Y; Z = -Z;
    }

    void fromAxisAngle(MathVector axis, double angleRadian)
    {
        double magnitude = axis.getLen();
        if (magnitude > 0.0001)
        {
            double ca = cos(angleRadian / 2);
            double sa = sin(angleRadian / 2);
            X = axis.X / magnitude * sa;
            Y = axis.Y / magnitude * sa;
            Z = axis.Z / magnitude * sa;
            W = ca;
        }
        else
        {
            W = 1; X = 0; Y = 0; Z = 0;
        }
    }

    Quaternion copy()
    {
        return Quaternion(W, X, Y, Z);
    }

    void set(const Quaternion & from) {
        this->W = from.W;
        this->X = from.X;
        this->Y = from.Y;
        this->Z = from.Z;
    }

    MathVector project(const MathVector & pt)
    {
        this->normalise();
        Quaternion q0 = this->copy();
        Quaternion q1 = this->copy();
        q1.conjugate();

        Quaternion qNode = Quaternion(0, pt.X, pt.Y, pt.Z);
        qNode = q0 * qNode * q1;

        return MathVector(qNode.X, qNode.Y, qNode.Z);
    }

    Quaternion operator*(Quaternion & right){
        double nw = this->W * right.W - this->X * right.X - this->Y * right.Y - this->Z * right.Z;
        double nx = this->W * right.X + this->X * right.W + this->Y * right.Z - this->Z * right.Y;
        double ny = this->W * right.Y + this->Y * right.W + this->Z * right.X - this->X * right.Z;
        double nz = this->W * right.Z + this->Z * right.W + this->X * right.Y - this->Y * right.X;
        return Quaternion(nw, nx, ny, nz);
    }



};

#endif // QUATERNION_H
