#ifndef PARTICLEINFO_H
#define PARTICLEINFO_H

#include <QVector3D>

struct ParticleInfo
{
public:
    ParticleInfo(double initAngle, QVector3D initSpeed, QVector3D initAcc, double initMass)
        : angle(initAngle), speed(initSpeed), acceleration(initAcc), mass(initMass) {}

    double angle;
    QVector3D speed;
    QVector3D acceleration;
    double mass;
};

#endif // PARTICLEINFO_H
