#include "particle.h"

QRectF Particle::boundingRect() const
{
    return QRectF(-500, 0, 1000, 500);
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

    MathVector projected = matrix->project(position);



//    MathVector projected = quat->Project(position);
// A good Idea
//    int rad = projected.Z / 10;
//    if (rad < 1)
//        rad = 1;
    int rad = 3;
    painter->drawEllipse(projected.X, projected.Y, rad, rad);
}
