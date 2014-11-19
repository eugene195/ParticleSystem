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
//    QRadialGradient radialGrad(QPointF(100, 100), 100);
//   radialGrad.setColorAt(0, Qt::red);
//   radialGrad.setColorAt(0.5, Qt::blue);
//   radialGrad.setColorAt(1, Qt::green);
//    MathVector projected = quat->Project(position);
// A good Idea
//    int rad = projected.Z / 10;
//    if (rad < 1)
//        rad = 1;
    int rad;
    if (projected.Z < 100)
        rad = 2;
    else if (projected.X < 180)
        rad = 4;
    else
        rad = 6;
//    int rad = 5;
    painter->drawEllipse(projected.X, projected.Y, rad, rad);

//    painter->setBrush(*(new QBrush(Qt::blue)));
//    painter->setPen(*(new QPen(Qt::black)));
//    painter->drawEllipse(projected.X, projected.Y, rad + 5, rad + 5);

//    painter->setBrush(*(new QBrush(Qt::white)));
//    painter->setPen(*(new QPen(Qt::white)));
//    painter->drawEllipse(projected.X, projected.Y, rad, rad);
}
