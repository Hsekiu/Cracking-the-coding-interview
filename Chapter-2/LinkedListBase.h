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
    void init(T n[]);
    void print();
    //node<T>* getHead();
    //node<T>* getTail();
    //void removeDupe();
    //node<T>* nthLast(int n);
    //void delMiddle(node<T> *middle);
    //node<T>* getLoop();
    //void addHead(T n);
    //bool isPalindrome();
    //bool updateTail();
    
protected:

	node *head;
    node *tail;
};

#endif