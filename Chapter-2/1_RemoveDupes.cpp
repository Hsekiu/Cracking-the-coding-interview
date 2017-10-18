#include "LinkedListBase.h"
#include <unordered_map>

class LinkedListExtension : public LinkedListBase {
    public:

    void removeDupe() {
        //Hash table to store each value occurence.
        std::unordered_map<int, bool> mymap;
        
        node *tmp = head;
        node *prev = nullptr;

        //Go through linked list while next node is not null.
        while(tmp != nullptr) {
            //If node in hash table it is not unique thus set pointer to next element.
            if(mymap[tmp->data]) {
                prev->next = tmp->next;
            //If is unique set it to true in table.
            } else {
                mymap[tmp->data] = true;
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