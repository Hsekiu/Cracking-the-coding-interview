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
    for(int i = 0; i < num; i++) {
        addVal(n[i]);
    }
}
template<class T>
void LinkedListBase<T>::print() {
    node *tmp = head;
    while(tmp != nullptr) {
        std::cout << "," << tmp->data;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}
/*
LinkedListBase::node* LinkedListBase::getHead() {
    return head;
}

LinkedListBase::node* LinkedListBase::getTail() {
    return tail;
}
*/
template<class T>
void LinkedListBase<T>::removeDupe() {
}
/*
LinkedListBase::node* LinkedListBase::nthLast(int n) {
    return nullptr;
}

void LinkedListBase::delMiddle(node *middle) {
}

LinkedListBase::node* LinkedListBase::getLoop() {
}

void LinkedListBase::addHead(int n) {
    node *NewNode = new node();
    NewNode->data = n;
    NewNode->next = head;
    head = NewNode;
    if(size == 0) {
        tail = head;
    }
}

bool LinkedListBase::isPalindrome() {
}

bool LinkedListBase::updateTail() {
    node *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tail = tmp;
}*/