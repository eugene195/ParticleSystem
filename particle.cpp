#include "particle.h"

QRectF Particle::boundingRect() const
{
    return QRectF(0, 0, 500, 500);
}

void Particle::step()
{
    speed = speed + acceleration;
    position = position + speed;
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::blue));
    painter->setPen(QPen(Qt::black));
    int rad = 2;
    painter->drawEllipse(position.getX(), position.getY(), rad, rad);
}
