#include "LinkedListBase.h"

LinkedListBase::LinkedListBase() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListBase::addVal(int n) {
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

void LinkedListBase::init(int n[], int num) {
    for(int i = 0; i < num; i++) {
        addVal(n[i]);
    }
}

void LinkedListBase::print() {
    node *tmp = head;
    while(tmp != nullptr) {
        std::cout << "," << tmp->data;
        tmp = tmp->next;
    }
     std::cout << std::endl;
}

void LinkedListBase::removeDupe() {
}

LinkedListBase::node* LinkedListBase::nthLast(int n) {
    return nullptr;
}

void LinkedListBase::delMiddle(node *middle) {
}

LinkedListBase::node* LinkedListBase::getHead() {
    return head;
}