#include "LinkedListBase.h"

class LinkedListExtension : public LinkedListBase {
    public:

    //Since we can't get the previous node's next pointer we must delete
   	//a node that is not this one thus replace all data with the next node
    //and delete that one.
    void delMiddle(node *middle) {
    	if(middle != nullptr || middle->next != nullptr) {
    		node *tmp = middle->next;
        	middle->data = middle->next->data;
        	middle->next = middle->next->next;
        	delete(tmp);
        	size--;
    	}
    }
};

int main() {
    LinkedListExtension list;
    
    int data[] = {5, 10 ,15, 5, 1, 4};
    list.init(data, sizeof(data)/sizeof(data[0]));

    list.print();
    std::cout << "Removing 3rd element" << std::endl;
    list.delMiddle((list.getHead())->next->next);
    list.print();
}