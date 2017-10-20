#include "LinkedListBase.h"
#include <unordered_map>

class LinkedListExtension : public LinkedListBase {
    public:

    void removeDupe() {
        //Hash table to store each value occurence.
        std::unordered_map<int, bool> mymap;
        
        node *curr = head;
        node *prev = nullptr;

        //Go through linked list while next node is not null.
        while(curr != nullptr) {
            //If node in hash table it is not unique thus set pointer to next element.
            if(mymap[curr->data]) {
                node *tmp = curr;
                prev->next = curr->next;
                delete(tmp);
                size--;
            //If is unique set it to true in table.
            } else {
                mymap[curr->data] = true;
                prev = curr;
            }
            curr = curr->next;
        }
    }
};

int main() {
    LinkedListExtension list;
    
    int data[] = {5, 10 ,15, 5, 1, 4};
    list.init(data, sizeof(data)/sizeof(data[0]));

    list.print();
    list.removeDupe();
    list.print();

    return 0;
}