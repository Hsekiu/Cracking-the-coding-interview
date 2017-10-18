#include "LinkedList.h"
#include <unordered_map>

class LinkedListExtension : public LinkedList {
    public:

    void removeDupe() {
        std::unordered_map<int, int> mymap;
        
        node *tmp = head;
        node *prev = nullptr;
        while(tmp != nullptr) {
            if(mymap[tmp->data]) {
                prev->next = tmp->next;
            } else {
                mymap[tmp->data] = 1;
                prev = tmp;
            }
            tmp = tmp->next;
        }
    }
};

int main() {
    LinkedListExtension list;
    
    list.addVal(5);
    list.addVal(10);
    list.addVal(15);
    list.addVal(5);
    list.addVal(1);
    list.addVal(4);
    list.addVal(4);

    list.print();
    list.removeDupe();
    list.print();

    return 0;
}