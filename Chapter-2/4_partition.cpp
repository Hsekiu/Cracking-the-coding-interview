#include "LinkedListBase.h"

LinkedListBase* partition(LinkedListBase* list1, int n) {
    //Start consists of values less then n and end greater then n.
    LinkedListBase* start = new LinkedListBase;
    LinkedListBase* end = new LinkedListBase;
    
    LinkedListBase::node* tmp = list1->getHead();
    
    while(tmp != nullptr) {
        if(tmp->data < n) {
            start->addVal(tmp->data);
        } else {
            end->addVal(tmp->data);
        }
        tmp = tmp->next;
    }
    
    //Add the end of the start to the start of end.
    start->getTail()->next = end->getHead();
    
    delete(end);
    return start;
}

int main() {
    LinkedListBase* list = new LinkedListBase;
    
    int data[] = {1, 4, 3, 2, 5, 2};
    list->init(data, sizeof(data)/sizeof(data[0]));

    list->print();
    list = partition(list, 3);
    list->print();

    delete(list);
    
    return 0;
}