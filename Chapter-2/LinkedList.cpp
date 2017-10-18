#include "LinkedList.h"

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedList::addVal(int n) {
    node *NewNode = new node();
    NewNode->data = n;
    NewNode->next = NULL;

    if(tail == NULL) {
        head = NewNode;
    } else {
        tail->next = NewNode;
    }
    tail = NewNode;
    size++;
}

void LinkedList::print() {
    node *tmp = head;
    while(tmp != nullptr) {
        std::cout << "," << tmp->data;
        tmp = tmp->next;
    }
     std::cout << std::endl;
}

void LinkedList::removeDupe() {
    printf("hello");
}