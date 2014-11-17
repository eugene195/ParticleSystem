#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include "context.h"
#include <cstdlib>

const int DEF_SPEED = 2;
const int DEF_ACC = 1;
const int DEF_EMISSION_RATE = 3;
const double DEF_SPREAD = 5;
const int DEFAULT_LIFETIME = 100;
const unsigned DEFAULT_RED = 0;
const unsigned DEFAULT_GREEN = 0;
const unsigned DEFAULT_BLUE = 0;
const unsigned DEFAULT_TRANSPARENCY = 25;
// Important
const int DEFAULT_SPREAD_MODIFIER = 1000000;

typedef QVector<Particle *> ParticleVector;

class Emitter
{
public:
    Emitter (const Context & context) {
        acceleration = *(MathVector *)context.get("acceleration");
        position = *(MathVector *)context.get("position");
        speed = *(MathVector *)context.get("speed");
        spread = *(double *)context.get("spread") / DEFAULT_SPREAD_MODIFIER;
        drawColor = *(QColor *)context.get("color");
        emissionRate = *(int *)context.get("emissionRate");
        lifetime = *(int *)context.get("lifetime");
        projector = (AbstractProjector *)context.get("projector");
    }

    ParticleVector emitParticles(){
        ParticleVector newParticles;

        for(int i = 0; i < emissionRate; ++i)
            newParticles.append(createParticle());
        return newParticles;
    }

    static QColor createColor(int transparency) {
        return QColor(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE, transparency);
    }

    Particle * createParticle(){
        MathVector angle(randomAngle(speed.getAngle().X), randomAngle(speed.getAngle().Y), randomAngle(speed.getAngle().Z));
        double length = speed.getLen();
        MathVector newPos = position;
        MathVector newSpeed = MathVector::fromAngle(angle, length);
        int lifetime = randomLifeTime();
        return new Particle(newSpeed, MathVector(), initMass , newPos, lifetime, projector, createColor(DEFAULT_TRANSPARENCY));
    }

    int randomLifeTime() {
        return lifetime + rand() % (int)(lifetime / 2);
    }
    double randomAngle(double current){
        return current + spread - (rand() * spread * 2);
    }

    void changeSpread(int spreadAddition) {
        spread = (spread + spreadAddition) / DEFAULT_SPREAD_MODIFIER;
    }

    void changeLifetime(int newLifetime) {
        lifetime = newLifetime;
    }

    void changeRate(int rateAddition) {
        emissionRate = rateAddition;
    }

private:
    MathVector acceleration;
    MathVector position;
    MathVector speed;
    double spread;
    QColor drawColor;
    int emissionRate;
    const double initMass = 0.06;
    int lifetime;

    AbstractProjector * projector;
};

#endif // EMITTER_H
