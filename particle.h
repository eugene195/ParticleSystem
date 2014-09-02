#ifndef PARTICLE_H
#define PARTICLE_H


#include <QGraphicsItem>
#include <QPainter>
#include "mathvector.h"

class Particle : public QGraphicsItem
{
public:
    Particle();
    Particle(MathVector initSpeed, MathVector initAcc, double initMass, MathVector initPos, QColor initColor = Qt::blue)
        : speed(initSpeed), acceleration(initAcc), mass(initMass),  position(initPos), color(initColor) {}

    QRectF boundingRect() const;
    void step();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    MathVector speed;
    MathVector acceleration;
    double mass;
    MathVector position;
    QColor color;


};

#endif // PARTICLE_H
