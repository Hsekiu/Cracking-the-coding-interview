#include "LinkedListBase.h"
#include "LinkedListBase.cpp"

template<class T>
LinkedListBase<T>* partition(LinkedListBase<T>* list1, T n) {
    //Start consists of values less then n and end greater then n.
    LinkedListBase<T>* start = new LinkedListBase<T>;
    LinkedListBase<T>* end = new LinkedListBase<T>;
    
    typename LinkedListBase<T>::node* tmp = list1->getHead();
    
    while(tmp != nullptr) {
        if(tmp->data < n) {
            start->addVal(tmp->data);
        } else {
            end->addVal(tmp->data);
        }
        tmp = tmp->next;
    }

    tmp = end->getHead();
    while(tmp != nullptr) {
        start->addVal(tmp->data);
        tmp = tmp->next;
    }
    
    delete(end);
    return start;
}

int main() {
    LinkedListBase<int>* list = new LinkedListBase<int>;
    
    int data[] = {1, 4, 3, 2, 5, 2};
    list->init(data, sizeof(data)/sizeof(data[0]));

    list->print();
    list = partition(list, 3);
    list->print();

    delete(list);
    
    return 0;
}