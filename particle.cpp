#include "particle.h"

void Particle::step()
{
    speed = speed + acceleration;
    position = position + speed;
}
