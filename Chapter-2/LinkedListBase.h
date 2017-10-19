#ifndef LinkedListBase_H
#define LinkedListBase_H

#include <stdio.h>
#include <iostream>

class LinkedListBase {

public:

    struct node {
        int data;
        node *next;
    };
    
    int size;

    LinkedListBase();
    void addVal(int n);
    void print();
    void removeDupe();
    node* nthLast(int n);
    
protected:

	node *head;
    node *tail;
};

#endif