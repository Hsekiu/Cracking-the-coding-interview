#include "LinkedListBase.h"
#include <unordered_map>

class LinkedListExtension : public LinkedListBase {
    public:

    node* getLoop() {
        //Create hash table of visited nodes.
        std::unordered_map<LinkedListBase::node*, int> mymap;

        LinkedListBase::node* tmp = head;
        //Go throught list, if node has not been seen add to hash table if it has return loop.
        //If list is normal it will naturally terminate with nullptr.
        while(tmp != nullptr) {
            if(mymap[tmp->next]) {
                return tmp->next;
                break;
            } else {
                mymap[tmp->next] = true;
            }
            tmp = tmp->next;
        }
        return nullptr;
    }
};

int main() {
    
    //Create normal list and initialize it with data.
    LinkedListExtension* list = new LinkedListExtension;
    int data[] = {1, 2, 3, 4, 5};
    list->init(data, sizeof(data)/sizeof(data[0]));
    list->print();

    //Make the list loop at 3.
    LinkedListExtension::node* l1 = list->getHead();
    l1 = l1->next->next;
    LinkedListExtension::node* l2 = list->getTail();
    l2->next = l1;

    LinkedListExtension::node * l3 = list->getLoop();
    if(l3 != nullptr) {
        int result = l3->data;
        std::cout << "Loop detected in: " << result << std::endl;
    }
    
    delete(list);
    
    return 0;
}