#include "emitter.h"

Emitter::Emitter (const Context & context) {
    acceleration = *(MathVector *)context.get("acceleration");
    position = *(MathVector *)context.get("position");
    speed = *(MathVector *)context.get("speed");
    spread = *(double *)context.get("spread") / DEFAULT_SPREAD_MODIFIER;
    drawColor = *(QColor *)context.get("color");
    emissionRate = *(int *)context.get("emissionRate");
    lifetime = *(int *)context.get("lifetime");
    projector = (AbstractProjector *)context.get("projector");

    drawColor = createColor(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE, DEFAULT_TRANSPARENCY);
    secondaryColor = createColor(0, 0, 255, 50);

    defPen.setColor(drawColor);
    defBrush.setColor(drawColor);

    secPen.setColor(secondaryColor);
    secBrush.setColor(secondaryColor);
}

ParticleVector Emitter::emitParticles() {
    ParticleVector newParticles;



    for(int i = 0; i < emissionRate; ++i)
        newParticles.append(createParticle());
    for(int i = 0; i < emissionRate; ++i)
        newParticles.append(createWParticle());
    return newParticles;
}

Particle * Emitter::createParticle() {
    MathVector angle(randomAngle(speed.getAngle().X), randomAngle(speed.getAngle().Y), randomAngle(speed.getAngle().Z));
    double length = speed.getLen();
    MathVector newPos = position;
    MathVector newSpeed = MathVector::fromAngle(angle, length);
    int lifetime = randomLifeTime();
    return new Particle(newSpeed, MathVector(), initMass , newPos, lifetime, projector, defPen, defBrush);
}

Particle * Emitter::createWParticle() {
    MathVector angle(randomAngle(speed.getAngle().X), randomAngle(speed.getAngle().Y), randomAngle(speed.getAngle().Z));
    double length = speed.getLen();
    MathVector newPos = position;
    MathVector newSpeed = MathVector::fromAngle(angle, length);
    int lifetime = randomLifeTime();
    return new Particle(newSpeed, MathVector(), initMass , newPos, lifetime, projector, secPen, secBrush);
}

void Emitter::changeSpread(int spreadAddition) {
    spread = (spread + spreadAddition) / DEFAULT_SPREAD_MODIFIER;
}

void Emitter::changeLifetime(int newLifetime) {
    lifetime = newLifetime;
}

void Emitter::changeRate(int rateAddition) {
    emissionRate = rateAddition;
}
