#ifndef StackBase_H
#define StackBase_H

#include "../Chapter-2/LinkedListBase.h"

class StackBase : public LinkedListBase {

public:
    
    StackBase();
    void init(int n[], int num);
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();

};

#endif