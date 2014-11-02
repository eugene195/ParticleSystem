#ifndef SCENEMATRIX_H
#define SCENEMATRIX_H

#include <QMatrix2x2>
#include <mathvector.h>

enum RotateDirection { XPOS, XNEG, YPOS, YNEG, ZPOS, ZNEG };

class SceneMatrix
{
public:
    SceneMatrix() {
        currentMatrix.setToIdentity();
        setAuxMatrices();
    }

    void rotateZPos() {
        currentMatrix = currentMatrix * rZPositiveMatrix;
    }

    void rotateZNeg() {
        currentMatrix = currentMatrix * rZNegativeMatrix;
    }

    void rotateYPos() {
        currentMatrix = currentMatrix * rYPositiveMatrix;
    }

    void rotateYNeg() {
        currentMatrix = currentMatrix * rYNegativeMatrix;
    }

    void rotateXPos() {
        currentMatrix = currentMatrix * rXPositiveMatrix;
    }

    void rotateXNeg() {
        currentMatrix = currentMatrix * rXNegativeMatrix;
    }

    MathVector project(const MathVector & in) const {
        return MathVector
        (
            in.X * currentMatrix(0, 0) + in.Y * currentMatrix(0, 1) + in.Z * currentMatrix(0, 2),
            in.X * currentMatrix(1, 0) + in.Y * currentMatrix(1, 1) + in.Z * currentMatrix(1, 2),
            in.X * currentMatrix(2, 0) + in.Y * currentMatrix(2, 1) + in.Z * currentMatrix(2, 2)
        );
    }




private:
    QMatrix3x3 currentMatrix;

    QMatrix3x3 rXPositiveMatrix;
    QMatrix3x3 rXNegativeMatrix;

    QMatrix3x3 rYPositiveMatrix;
    QMatrix3x3 rYNegativeMatrix;

    QMatrix3x3 rZPositiveMatrix;
    QMatrix3x3 rZNegativeMatrix;

    const double angle = sin(M_PI / 40);

    void setAuxMatrices() {
        setXMatrix(angle, rXPositiveMatrix);
        setXMatrix(-angle, rXNegativeMatrix);

        setYMatrix(angle, rYPositiveMatrix);
        setYMatrix(-angle, rYNegativeMatrix);

        setZMatrix(angle, rZPositiveMatrix);
        setZMatrix(-angle, rZNegativeMatrix);
    }

    void setXMatrix(double ang, QMatrix3x3 & matrixToSet) {
        float * rotX = new float(9);
        rotX = matrixToSet.data();
        rotX[0] = 1, rotX[1] = 0,         rotX[2] = 0;
        rotX[3] = 0, rotX[4] = cos(ang),  rotX[5] = -sin(ang);
        rotX[6] = 0, rotX[7] = sin(ang),  rotX[8] = cos(ang);
    }

    void setYMatrix(double ang, QMatrix3x3 & matrixToSet) {
        float * rotPosZ = new float(9);
        rotPosZ = matrixToSet.data();
        rotPosZ[0] = cos(ang),  rotPosZ[1] = 0,  rotPosZ[2] = sin(ang);
        rotPosZ[3] = 0,         rotPosZ[4] = 1,  rotPosZ[5] = 0;
        rotPosZ[6] = -sin(ang), rotPosZ[7] = 0,  rotPosZ[8] = cos(ang);
    }

    void setZMatrix(double ang, QMatrix3x3 & matrixToSet) {
        float * rotZ = new float(9);
        rotZ = matrixToSet.data();
        rotZ[0] = cos(ang), rotZ[1] = -sin(ang), rotZ[2] = 0;
        rotZ[3] = sin(ang), rotZ[4] = cos(ang),  rotZ[5] = 0;
        rotZ[6] = 0,          rotZ[7] = 0,       rotZ[8] = 1;
    }
};

#endif // SCENEMATRIX_H
