#ifndef LinkedList_H
#define LinkedList_H

#include <stdio.h>
#include <iostream>

class LinkedList {

public:

    struct node {
        int data;
        node *next;
    };
    
    int size;

    LinkedList();
    void addVal(int n);
    void print();
    void removeDupe();
    
protected:
	
	node *head;
    node *tail;
};

#endif