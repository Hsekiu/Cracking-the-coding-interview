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
    void init(int n[], int num);
    void print();
    node* getHead();
    node* getTail();
    void removeDupe();
    node* nthLast(int n);
    void delMiddle(node *middle);
    node* getLoop();
    
protected:

	node *head;
    node *tail;
};

#endif