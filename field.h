#ifndef FIELD_H
#define FIELD_H

#include "mathvector.h"

const int DEF_POWER = 20;

class Field
{
public:
    Field(MathVector * coordinates, double newPower = DEF_POWER){
        position = coordinates;
        power = newPower;
    }
    ~Field() {
        delete position;
    }


    MathVector getPosition() const{
        return *position;
    }

    double getPower() const {
        return power;
    }

    void changeField(QString parameter, double value) {
        if (parameter == "power")
            power = value;
    }

private:
    MathVector * position;
    double power;
};

typedef QList<Field *> FieldList;

#endif // FIELD_H
