#ifndef LinkedListBase_H
#define LinkedListBase_H

#include <stdio.h>
#include <iostream>
#include <stdexcept>

template<class T>
class LinkedListBase {

public:

    struct node {
        T data;
        node *next;
    };
    
    int size;

    LinkedListBase();
    void addVal(T n);
    void init(T n[], int num);
    void print();
    node* getHead();
    node* getTail();
    void addHead(T n);
    bool updateTail();
    
protected:

	node *head;
    node *tail;
};

#endif