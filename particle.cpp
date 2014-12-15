#include "particle.h"
#include <QDebug>
QRectF Particle::boundingRect() const
{
    return QRectF(-1000, -1000, 2000, 2000);
}

void Particle::applyField(const FieldList &fldlst)
{
    MathVector totalAcc;
    foreach(Field * field, fldlst){
        MathVector distanceToFld = field->getPosition() - this->position;
        double force = (field->getPower() * this->mass) / pow(distanceToFld.getLen(), 1.5);
        totalAcc = totalAcc + distanceToFld * force;
    }
    this->acceleration = totalAcc;
}

void Particle::advance()
{
    --lifeTime;
    speed = speed + acceleration;
    position = position + speed;
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->setPen(pen);

    MathVector projected = projector->project(position);

    int rad;
    if (projected.Z < 100)
        rad = 2;
    else if (projected.X < 180)
        rad = 4;
    else
        rad = 6;
    painter->drawEllipse(projected.X, projected.Y, rad, rad);
}
