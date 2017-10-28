#ifndef StackBase_H
#define StackBase_H

#include "../Chapter-2/LinkedListBase.h"

class StackBase : public LinkedListBase {

public:
    
    StackBase();
    void push(int data);
    int pop();
    void print();

};

#endif