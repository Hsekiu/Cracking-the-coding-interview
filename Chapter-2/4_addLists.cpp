#include "LinkedListBase.h"

LinkedListBase* addLists(LinkedListBase* list1, LinkedListBase *list2) {
    // Create nodes to traverse the list with.
    LinkedListBase::node* l1 = list1->getHead();
    LinkedListBase::node* l2 = list2->getHead();
    int val = 0, carry = 0;
    
    LinkedListBase* result = new LinkedListBase;
    
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
    LinkedListBase* list1 = new LinkedListBase;
    LinkedListBase* list2 = new LinkedListBase;
    
    int data1[] = {1, 2 ,3, 4, 5, 6};
    list1->init(data1, sizeof(data1)/sizeof(data1[0]));

    int data2[] = {1, 2 ,3, 4, 5, 6};
    list2->init(data2, sizeof(data2)/sizeof(data2[0]));

    LinkedListBase* list3 = addLists(list1, list2);
    
    std::cout << "List1 is: ";
    list1->print();
    std::cout << "List2 is: ";
    list2->print();
    std::cout << "Addition of List1 and List2 is: ";
    list3->print();
    
    //delete(list1);
    //delete(list2);

    return 0;
}