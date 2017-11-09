#include "LinkedListBase.h"
#include "LinkedListBase.cpp"

/*
    Assume that the intersection only happens at the end of a list and that all elements are
    the same between intersections. Then you only have to check the last elements, if the
    pointers are the same they must be the same node in memory thus the two lists share the 
    same node and thus must be intersecting.
    
*/

template<class T>
bool isIntersection(LinkedListBase<T>* list1, LinkedListBase<T>* list2) {
    if(list1->getTail() == list2->getTail()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    
    LinkedListBase<int>* list1 = new LinkedListBase<int>;
    LinkedListBase<int>* list2 = new LinkedListBase<int>;
    LinkedListBase<int>* list3 = new LinkedListBase<int>;
    LinkedListBase<int>* list4 = new LinkedListBase<int>;
    
    int data1[] = {1, 2};
    list1->init(data1, sizeof(data1)/sizeof(data1[0]));
    std::cout << "First list non intersecting: ";
    list1->print();
    
    int data2[] = {3, 4};
    list2->init(data2, sizeof(data2)/sizeof(data2[0]));
    std::cout << "Second list non intersecting: ";
    list2->print();
    
    int data3[] = {8, 9};
    list3->init(data3, sizeof(data3)/sizeof(data3[0]));
    std::cout << "Third list that first and second list will be intersecting: ";
    list3->print();
    
    int data4[] = {1, 2, 8, 9};
    list4->init(data4, sizeof(data4)/sizeof(data4[0]));
    std::cout << "Fourth non intersecting list with same last value: ";
    list4->print();
    
    list1->getTail()->next = list3->getHead();
    list2->getTail()->next = list3->getHead();
    
    std::cout << "First list intersecting: ";
    list1->print();
    std::cout << "Second list intersecting: ";
    list2->print();
    
    /*
        Since pointers are moved around manually the tail is now points to the original position.
        Could set it here manually with setTail function at constant time but I went with a method
        That goes through the list and sets it dynamically.
    */
    list1->updateTail();
    list2->updateTail();
    
    std::cout << "List 1 and List 2 intersect, " << 
    (isIntersection(list1, list2) ? "true" : "false") << std::endl;
    std::cout << "List 1 and List 4 intersect, " << 
    (isIntersection(list1, list4) ? "true" : "false") << std::endl;
    
    delete(list1);
    delete(list2);
    delete(list3);
    delete(list4);

    return 0;
}