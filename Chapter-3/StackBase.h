#ifndef StackBase_H
#define StackBase_H

#include "../Chapter-2/LinkedListBase.h"
#include "../Chapter-2/LinkedListBase.cpp"

template<class T>
class StackBase : public LinkedListBase<T> {

public:
    
    StackBase();
    virtual void init(T n[], int num);
    virtual void push(T data);
    virtual T pop();
    virtual T peek();
    virtual bool isEmpty();

};

#endif