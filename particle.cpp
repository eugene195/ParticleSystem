#include "particle.h"

void Particle::step()
{
    info.speed += info.acceleration;
    position += info.speed;
}
