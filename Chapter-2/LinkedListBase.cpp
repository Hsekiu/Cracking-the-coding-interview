#include "LinkedListBase.h"

template<class T>
LinkedListBase<T>::LinkedListBase() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void LinkedListBase<T>::addVal(T n) {
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

template<class T>
void LinkedListBase<T>::init(T n[], int num) {
    int size = num;
    for(int i = 0; i < size; i++) {
        addVal(n[i]);
    }
}
template<class T>
void LinkedListBase<T>::print() {
    node *tmp = head;
    for(int i = 0; i < size; i++) {
        std::cout << "," << tmp->data;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template<class T>
typename LinkedListBase<T>::node* LinkedListBase<T>::getHead() {
    return head;
}

template<class T>
typename LinkedListBase<T>::node* LinkedListBase<T>::getTail() {
    return tail;
}
/*
void LinkedListBase::addHead(int n) {
    node *NewNode = new node();
    NewNode->data = n;
    NewNode->next = head;
    head = NewNode;
    if(size == 0) {
        tail = head;
    }
}

bool LinkedListBase::updateTail() {
    node *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tail = tmp;
}*/