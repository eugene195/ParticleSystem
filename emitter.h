#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include <cstdlib>

const int DEF_SPEED = 2;
const int DEF_ACC = 1;
const int DEF_EMISSION_RATE = 3;
const double DEF_SPREAD = 5;
class Emitter
{
public:
    Emitter(MathVector initPos = MathVector()
            , MathVector initSpeed = MathVector(DEF_SPEED, DEF_SPEED, 0)
            , double initSpread = DEF_SPREAD
            , QColor initColor = Qt::blue
            , int initEmissionRate = DEF_EMISSION_RATE)
        : position(initPos), speed(initSpeed), spread(initSpread / 1000000), drawColor(initColor), emissionRate(initEmissionRate) {}

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

        int m1 = 0;
        int m2 = 2;
        int out = m1 + (rand() % (int)(m2 - m1 + 1));
        QColor col;
        if(out == 0)
            col = Qt::blue;
        else if(out == 1)
            col = Qt::green;
        else
            col = Qt::red;


        return new Particle(newSpeed, MathVector(), initMass , newPos, col); // InitMass
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
