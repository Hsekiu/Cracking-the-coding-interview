#include "LinkedListBase.h"
#include "LinkedListBase.cpp"
#include <unordered_map>

template<class T>
class LinkedListExtension : public LinkedListBase<T> {
    public:

    void removeDupe() {
        //Hash table to store each value occurence.
        std::unordered_map<int, bool> mymap;

        typename LinkedListBase<T>::node *curr = LinkedListBase<T>::head;
        typename LinkedListBase<T>::node *prev = nullptr;

        //Go through linked list while next node is not null.
        while(curr != NULL) {
            //If node in hash table it is not unique thus set pointer to next element.
            if(mymap[curr->data]) {
                typename LinkedListBase<T>::node *tmp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(tmp);
                LinkedListBase<T>::size--;
            //If is unique set it to true in table.
            } else {
                mymap[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
    }
};

int main() {
    LinkedListExtension<char> list;
    
    char data[] = {'a', 'd', 'e', 'f', 'a', 'c'};
    list.init(data, sizeof(data)/sizeof(data[0]));

    list.print();
    list.removeDupe();
    list.print();

    return 0;
}