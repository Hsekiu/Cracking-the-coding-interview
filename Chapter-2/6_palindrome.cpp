#include "LinkedListBase.h"

class LinkedListExtension : public LinkedListBase {
    public:

    bool isPalindrome() {
        node *tmp = head;
        LinkedListExtension rev;

        //Create a reversed list.
        while(tmp != nullptr) {
            rev.addHead(tmp->data);
            tmp = tmp->next;
        }

        //Reset tmp and get start of reverse list.
        tmp = head;
        node *tmp2 = rev.getHead();
        
        //Compare the reversed list and input list if not equal then not palindrome.
        while(tmp != nullptr) {
            if(tmp->data != tmp2->data) {
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        
        return true;
    }
};

int main() {
    LinkedListExtension list;
    
    int data[] = {1, 2, 5, 3, 5, 2, 1};
    list.init(data, sizeof(data)/sizeof(data[0]));
    
    list.print();
    std::cout << "Is a palindrome " << (list.isPalindrome() ? "true" : "false") << std::endl;

    LinkedListExtension list2;
    int data2[] = {2, 2, 5, 3, 4, 2, 1};
    list2.init(data2, sizeof(data2)/sizeof(data2[0]));

    std::cout << std::endl;

    list2.print();
    std::cout << "Is a palindrome " << (list2.isPalindrome() ? "true" : "false") << std::endl;

    return 0;
}