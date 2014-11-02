#ifndef CONTEXT_H
#define CONTEXT_H

#include <QVector>

template <class K>
class Context
{
public:
    Context();
private:
    QVector<std::pair<K, QString>> vec;
};

#endif // CONTEXT_H
