#ifndef FIELD_H
#define FIELD_H

#include "mathvector.h"

const int DEF_MASS = 20;

class Field
{
public:
    Field(MathVector * coordinates, double newMass = DEF_MASS){
        position = coordinates;
        mass = newMass;
    }


    MathVector getPosition() const{
        return *position;
    }

    double getMass() const {
        return mass;
    }

private:
    MathVector * position;
    double mass;
};

typedef QList<Field *> FieldList;

#endif // FIELD_H
