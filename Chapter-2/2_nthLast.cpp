#include "LinkedListBase.h"
#include <unordered_map>

class LinkedListExtension : public LinkedListBase {
    public:

    node* nthLast(int nth) {
        //Since linked list implementation has size find the pos of nth to last element.
        int pos = (size - nth + 1);
        node *tmp = head;
        int count = 1;
        
        //Go through linked list till nth to last element is hit
        while(tmp != NULL) {
            if(count == pos) {
                return tmp;
            }
            count++;
            tmp = tmp->next;
        }
        
        return nullptr;
    }
};

int main() {
    LinkedListExtension list;
    
    int data[] = {5, 10 ,15, 5, 1, 4};
    list.init(data, sizeof(data)/sizeof(data[0]));

    list.print();
    std::cout << "First to last element is: " << (list.nthLast(1))->data << std::endl;
    std::cout << "Second to last element is: " << (list.nthLast(2))->data << std::endl;
    std::cout << "Third to last element is: " << (list.nthLast(3))->data << std::endl;

    return 0;
}