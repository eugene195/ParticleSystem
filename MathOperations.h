#pragma once
#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include <QPointF>
#include "mathvector.h"
class Rotator {
public:
    static double rotateXCoordinate(double xCenter, double xOld, double yCenter, double yOld, double angle){
        return xCenter + (xOld - xCenter) * cos(angle) + (yCenter - yOld) * sin(angle);
    }

    static double rotateYCoordinate(double xCenter, double xOld, double yCenter, double yOld, double angle){
        return xCenter + (xOld - xCenter) * sin(angle) + (yOld - yCenter) * cos(angle);
    }

    static void zOrientedRotate(MathVector &node, const MathVector &massCentre, double angle)
    {
        double oldX = node.X;
        double oldY = node.Y;

        node.X = Rotator::rotateXCoordinate(massCentre.X, oldX, massCentre.Y, oldY, angle);
        node.Y = Rotator::rotateYCoordinate(massCentre.X, oldX, massCentre.Y, oldY, angle);
    }


    static void yOrientedRotate(MathVector &node, MathVector &massCentre, double angle)
    {
        double oldX = node.X;
        double oldZ = node.Z;

        node.X = Rotator::rotateXCoordinate(massCentre.X, oldX, massCentre.Z, oldZ, angle);
        node.Z = Rotator::rotateYCoordinate(massCentre.X, oldX, massCentre.Z, oldZ, angle);
    }


    static void xOrientedRotate(MathVector &node, MathVector &massCentre, double angle)
    {
        double oldY = node.Y;
        double oldZ = node.Z;

        node.Y = Rotator::rotateXCoordinate(massCentre.Y, oldY, massCentre.Z, oldZ, angle);
        node.Z = Rotator::rotateYCoordinate(massCentre.Y, oldY, massCentre.Z, oldZ, angle);
    }
};



class Side {
public:
    Side() : P1(MathVector()), P2(MathVector()) {}
    Side(MathVector pnt1, MathVector pnt2) : P1(pnt1), P2(pnt2) {}

    MathVector& getP2() const;
    void setP2(const MathVector &value);
    MathVector& getP1() const;
    void setP1(const MathVector &value);

public:
    MathVector P1, P2;
};


#endif // MATHOPERATIONS_H
