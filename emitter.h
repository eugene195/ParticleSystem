#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"

class Emitter
{
public:
    Emitter(QVector3D initPos = QVector3D(0, 0, 0)
            , QVector3D initSpeed = QVector3D(0, 0, 0)
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
//        Particle * newParticle = new Particle();
        return 0;
    }

private:
    QVector3D position;
    QVector3D speed;
    double spread;
    QColor drawColor;
    int emissionRate;
};

#endif // EMITTER_H
