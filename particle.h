#ifndef PARTICLE_H
#define PARTICLE_H


#include <QGraphicsItem>
#include <QPainter>
#include "mathvector.h"
#include "field.h"

class Particle : public QGraphicsItem
{
public:
    Particle();
    Particle(MathVector initSpeed, MathVector initAcc, double initMass, MathVector initPos, QColor initColor = Qt::blue)
        : speed(initSpeed), acceleration(initAcc), mass(initMass),  position(initPos), color(initColor) {}

    QRectF boundingRect() const;

    void applyField(const FieldList &fldlst);
    void advance()
    {
        speed = speed + acceleration;
        position = position + speed;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    double getX(){
        return position.getX();
    }
    double getY(){
        return position.getY();
    }
    double getZ(){
        return position.getZ();
    }

private:
    MathVector speed;
    MathVector acceleration;
    double mass;
    MathVector position;
    QColor color;


};

#endif // PARTICLE_H
