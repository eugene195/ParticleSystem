#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include <cstdlib>
class Emitter
{
public:
    Emitter(MathVector initPos = MathVector()
            , MathVector initSpeed = MathVector()
            , double initSpread = 0.15
            , QColor initColor = Qt::blue
            , int initEmissionRate = 1)
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

//        Particle * newParticle = new Particle();
        return new Particle(newSpeed, MathVector(), 0.2 , newPos); // InitMass
    }

    double randomAngle(double current){
        return current + spread - (rand()* spread * 2);
    }

private:
    MathVector position;
    MathVector speed;
    double spread;
    QColor drawColor;
    int emissionRate;
};

#endif // EMITTER_H
