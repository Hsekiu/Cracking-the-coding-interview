#ifndef StackBase_H
#define StackBase_H

#include "../Chapter-2/LinkedListBase.h"

class StackBase : public LinkedListBase {

public:
    
    StackBase();
    virtual void init(int n[], int num);
    virtual void push(int data);
    virtual int pop();
    virtual int peek();
    virtual bool isEmpty();

};

#endif