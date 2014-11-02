#ifndef PARTICLE_H
#define PARTICLE_H


#include <QGraphicsItem>
#include <QPainter>
#include "scenematrix.h"
#include "field.h"

class Particle : public QGraphicsItem
{
public:
    Particle();
    Particle(
             MathVector initSpeed, MathVector initAcc,
             double initMass, MathVector initPos,
             SceneMatrix * newMatrix, int initLifeTime,
             QColor initColor = QColor(0, 0, 255, 255)
            ) :
          speed(initSpeed), acceleration(initAcc),
          mass(initMass),  position(initPos),
          color(initColor), lifeTime(initLifeTime),
          matrix(newMatrix)
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
    int lifeTime;
    //    It is very unnecessary
    SceneMatrix * matrix;



};

#endif // PARTICLE_H
