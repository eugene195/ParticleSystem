#ifndef PARTICLE_H
#define PARTICLE_H

#include "particleinfo.h"

#include <QGraphicsItem>


class Particle : public QGraphicsItem
{
public:
    Particle(ParticleInfo initInfo, QVector3D initPos, QColor initColor = Qt::blue)
        : info(initInfo),  position(initPos), color(initColor) {}

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void step();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    ParticleInfo info;
    QVector3D position;
    QColor color;

};

#endif // PARTICLE_H
