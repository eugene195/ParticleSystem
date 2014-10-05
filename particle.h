#ifndef PARTICLE_H
#define PARTICLE_H


#include <QGraphicsItem>
#include <QPainter>
#include "MathOperations.h"
#include "mathvector.h"
#include "math.h"
#include "field.h"

const unsigned DEFAULT_COLOR_ALPHA = 255;
const int INIT_RADIUS = 10;
const double DEF_ANGLE = M_PI_4;


class Particle : public QGraphicsItem
{
public:
    Particle();
    Particle(MathVector initSpeed, MathVector initAcc, double initMass, MathVector initPos, QColor initColor = Qt::blue, int initLifeTime = 255)
        : speed(initSpeed), acceleration(initAcc), mass(initMass),  position(initPos), color(initColor), lifeTime(initLifeTime)
    {
        radius = INIT_RADIUS;

//        TODO!!
        nodes.append(MathVector(position + MathVector(radius, 0, 0)));
        nodes.append(MathVector(position + MathVector(-radius, 0, 0)));
        nodes.append(MathVector(position + MathVector(0, radius, 0)));
        nodes.append(MathVector(position + MathVector(0, -radius, 0)));
        nodes.append(MathVector(position + MathVector(0, 0, radius)));
        nodes.append(MathVector(position + MathVector(0, 0, -radius)));

        brush = new QBrush(color);
        pen = new QPen(color);
    }

    QRectF boundingRect() const;

    void applyField(const FieldList &fldlst);
    void advance()
    {
        speed = speed + acceleration;


        for(int i = 0; i < nodes.size(); ++i){
            nodes[i] = nodes[i] + speed;
            // Angle doesn't work here
            Rotator::zOrientedRotate(nodes[i], position, M_PI_4 / 10);
        }
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

    int radius;
    QVector<MathVector> nodes;

    QPen *pen;
    QBrush *brush;
    // STILL NOT USED
    int lifeTime;


};

#endif // PARTICLE_H
