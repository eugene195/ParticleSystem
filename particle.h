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
    Particle(
            MathVector initSpeed, MathVector initAcc,
             double initMass, MathVector initPos,
             QColor initColor = QColor(0, 0, 255, 255), int initLifeTime = 255
            )
        : speed(initSpeed), acceleration(initAcc),
          mass(initMass),  position(initPos),
          color(initColor), lifeTime(initLifeTime)
    {
        brush = new QBrush(initColor);
        pen = new QPen(initColor);
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
    double getX(){
        return position.getX();
    }
    double getY(){
        return position.getY();
    }
    double getZ(){
        return position.getZ();
    }

    bool isAlive() const {
        return lifeTime > 0;
    }

    int getLifeTime() const{
        return lifeTime;
    }

    void killParticle(){
        lifeTime = 0;
    }

private:
    MathVector speed;
    MathVector acceleration;
    double mass;
    MathVector position;
    QColor color;

    QPen *pen;
    QBrush *brush;
    // STILL NOT USED
    int lifeTime;


};

#endif // PARTICLE_H
