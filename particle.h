#ifndef PARTICLE_H
#define PARTICLE_H


#include <QGraphicsItem>
#include <QPainter>
#include "field.h"
#include "Projectors/projector.h"

class Particle : public QGraphicsItem
{
public:
    Particle();
    Particle(
             MathVector initSpeed, MathVector initAcc,
             double initMass, MathVector initPos,
             int initLifeTime,
             AbstractProjector * initProjector,
             QPen & initPen, QBrush & initBrush,
             QColor initColor = QColor(0, 0, 255, 255)
            ) :
          speed(initSpeed), acceleration(initAcc),
          mass(initMass),  position(initPos),
          color(initColor), lifeTime(initLifeTime),
          pen(initPen), brush(initBrush),
          projector(initProjector)
    {
//        THis is a bug TODO
    }

    QRectF boundingRect() const;

    void applyField(const FieldList &fldlst);
    void advance()
    {
        --lifeTime;

        speed = speed + acceleration;
        position = position + speed;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    double X() const {
        return position.X;
    }

    double Y() const {
        return position.Y;
    }

    double Z() const {
        return position.Z;
    }

    bool isAlive() const {
        return lifeTime > 0;
    }

    int getLifeTime() const{
        return lifeTime;
    }

private:
    MathVector speed;
    MathVector acceleration;
    double mass;
    MathVector position;
    QColor color;


    int lifeTime;
    QPen pen;
    QBrush brush;
    //    It is very unnecessary. Static methods
    AbstractProjector * projector;


};

#endif // PARTICLE_H
