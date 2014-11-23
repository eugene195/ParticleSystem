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
const unsigned DEFAULT_RED = 255;
const unsigned DEFAULT_GREEN = 255;
const unsigned DEFAULT_BLUE = 255;
const unsigned DEFAULT_TRANSPARENCY = 100;
// Important
const int DEFAULT_SPREAD_MODIFIER = 1000000;

typedef QVector<Particle *> ParticleVector;

class Emitter
{
public:
    Emitter (const Context & context);
    ParticleVector emitParticles();

//    Типа конструктивное решение - хранить партиклы в куче
    Particle * createParticle();
    Particle * createWParticle();
    void changeSpread(int spreadAddition);
    void changeLifetime(int newLifetime);
    void changeRate(int rateAddition);

    void changeColor(int red, int green, int blue, int transparency);

    int randomLifeTime() {
        return lifetime + rand() % (int)(lifetime / 2);
    }
    double randomAngle(double current){
        return current + spread - (rand() * spread * 2);
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

    QPen defPen;
    QBrush defBrush;
};

#endif // EMITTER_H
