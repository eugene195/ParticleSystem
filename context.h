#ifndef CONTEXT_H
#define CONTEXT_H

#include <QVector>

typedef std::pair<void *, QString> Pairable;

class Context
{
public:
    Context() { vec.resize(5); }
    void add(const void * element, const QString val) {
        Pairable pair(element, val);
        vec.append(pair);
    }

    void * get(QString name) const {
        foreach (Pairable pair, vec) {
            if (pair.second == name)
                return pair.first;
        }
        return NULL;
    }

private:
    QVector<Pairable> vec;
};

#endif // CONTEXT_H
