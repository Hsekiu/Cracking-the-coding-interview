#include "LinkedListBase.h"
#include "LinkedListBase.cpp"

template<class T>
LinkedListBase<T>* addLists(LinkedListBase<T>* list1, LinkedListBase<T> *list2) {
    // Create nodes to traverse the list with.
    typename LinkedListBase<T>::node* l1 = list1->getHead();
    typename LinkedListBase<T>::node* l2 = list2->getHead();
    int val = 0, carry = 0;
    
    LinkedListBase<T>* result = new LinkedListBase<T>;
    
    // While neither list is empty loop.
    while(l1 != nullptr || l2 != nullptr) {
        val = l1->data + l2->data + carry;
        
        // There is a carry.
        if(val > 9) {
            carry = 1;
            val = val - 10;
        }
        
        result->addVal(val);
        l1 = l1->next;
        l2 = l2->next;
    }
    
    //If last elements in list result in carry create another node with it.
    if(carry > 0) {
        result->addVal(carry);
    }
    
    return result;
}

int main() {
    LinkedListBase<int>* list1 = new LinkedListBase<int>;
    LinkedListBase<int>* list2 = new LinkedListBase<int>;
    
    int data1[] = {1, 2 ,3, 4, 5, 6};
    list1->init(data1, sizeof(data1)/sizeof(data1[0]));

    int data2[] = {1, 2 ,3, 4, 5, 6};
    list2->init(data2, sizeof(data2)/sizeof(data2[0]));

    LinkedListBase<int>* list3 = addLists(list1, list2);
    
    std::cout << "List1 is: ";
    list1->print();
    std::cout << "List2 is: ";
    list2->print();
    std::cout << "Addition of List1 and List2 is: ";
    list3->print();
    
    delete(list1);
    delete(list2);

    return 0;
}