#include "particle.h"

QRectF Particle::boundingRect() const
{
    return QRectF(0, 0, 500, 500);
}

void Particle::applyField(const FieldList &fldlst)
{
    MathVector totalAcc;
    foreach(Field * field, fldlst){
        MathVector distanceToFld = field->getPosition() - this->position;
        double force = (field->getMass() * this->mass) / pow(distanceToFld.getLen(), 1.5);
        totalAcc = distanceToFld * force;
    }
    this->acceleration = totalAcc;
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::blue));
    painter->setPen(QPen(Qt::black));
    int rad = 5;
    painter->drawEllipse(position.getX(), position.getY(), rad, rad);
}
