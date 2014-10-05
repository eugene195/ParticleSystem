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
    painter->setBrush(*brush);
    painter->setPen(*pen);
    int sz = nodes.size();

    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < sz; ++j) {
            if(i != j)
                painter->drawLine(nodes[i].toPoint(), nodes[j].toPoint());
        }
    }
}
