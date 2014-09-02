#include "particle.h"

QRectF Particle::boundingRect() const
{

}

void Particle::step()
{
    speed = speed + acceleration;
    position = position + speed;
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
