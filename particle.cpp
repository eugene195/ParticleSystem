#include "particle.h"

QRectF Particle::boundingRect() const
{
    return QRectF(-500, -500, 1000, 1000);
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

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    int rad = 3;
//    qDebug() << position.X;
    MathVector projected = matrix->project(position);
//    qDebug() << projected.X;
    painter->drawEllipse(projected.X, projected.Y, rad, rad);
}
