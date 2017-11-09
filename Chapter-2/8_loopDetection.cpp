#include "LinkedListBase.h"
#include "LinkedListBase.cpp"
#include <unordered_map>

template<class T>
class LinkedListExtension : public LinkedListBase<T> {
    public:

    typename LinkedListBase<T>::node* getLoop() {
        //Create hash table of visited nodes.
        std::unordered_map<typename LinkedListBase<T>::node*, bool> mymap;

        typename LinkedListBase<T>::node* tmp = LinkedListBase<T>::head;
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
    LinkedListExtension<int>* list = new LinkedListExtension<int>;
    int data[] = {1, 2, 3, 4, 5};
    list->init(data, sizeof(data)/sizeof(data[0]));
    list->print();

    std::cout << "Made list loop at 3" << std::endl;
    //Make the list loop at 3.
    typename LinkedListBase<int>::node* l1 = list->getHead();
    l1 = l1->next->next;
    typename LinkedListBase<int>::node* l2 = list->getTail();
    l2->next = l1;

    typename LinkedListBase<int>::node* l3 = list->getLoop();
    if(l3 != nullptr) {
        int result = l3->data;
        std::cout << "Loop detected in: " << result << std::endl;
    }
    
    delete(list);
    
    return 0;
}