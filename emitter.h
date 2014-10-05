#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include <cstdlib>

const int DEF_SPEED = 1;
const int DEF_ACC = 1;
const int DEF_EMISSION_RATE = 1;
const double DEF_SPREAD = 0.000020;
class Emitter
{
public:
    Emitter(MathVector initPos = MathVector()
            , MathVector initSpeed = MathVector(DEF_SPEED, DEF_SPEED, 0)
            , double initSpread = DEF_SPREAD
            , QColor initColor = Qt::blue
            , int initEmissionRate = DEF_EMISSION_RATE)
        : position(initPos), speed(initSpeed), spread(initSpread), drawColor(initColor), emissionRate(initEmissionRate) {}

    QList<Particle *> emitParticles(){
        QList<Particle *> newParticles;
        for(int i = 0; i < emissionRate; ++i)
            newParticles.append(createParticle());
        return newParticles;
    }

    Particle * createParticle(){
        MathVector angle(randomAngle(speed.getAngle().getX()), randomAngle(speed.getAngle().getY()), randomAngle(speed.getAngle().getZ()));
        double length = speed.getLen();
        MathVector newPos = position;
        MathVector newSpeed = MathVector::fromAngle(angle, length);
        return new Particle(newSpeed, MathVector(), initMass , newPos); // InitMass
    }

    double randomAngle(double current){
        return current + spread - (rand() * spread * 2);
    }

private:
    MathVector position;
    MathVector speed;
    double spread;
    QColor drawColor;
    int emissionRate;
    const double initMass = 0.06;
};

#endif // EMITTER_H
