#include "LinkedListBase.h"
#include "LinkedListBase.cpp"

template<class T>
class LinkedListExtension : public LinkedListBase<T> {
    public:

    bool isPalindrome() {
        typename LinkedListBase<T>::node *tmp = LinkedListBase<T>::head;
        LinkedListExtension rev;

        //Create a reversed list.
        while(tmp != nullptr) {
            rev.addHead(tmp->data);
            tmp = tmp->next;
        }

        //Reset tmp and get start of reverse list.
        tmp = LinkedListBase<T>::head;
        typename LinkedListBase<T>::node *tmp2 = rev.getHead();
        
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
    LinkedListExtension<char> list;
    
    char data[] = {'a', 'b', 'c', 'b', 'a'};
    list.init(data, sizeof(data)/sizeof(data[0]));
    
    list.print();
    std::cout << "Is a palindrome " << (list.isPalindrome() ? "true" : "false") << std::endl;

    LinkedListExtension<char> list2;
    char data2[] = {'b', 'b', 'c', 'e', 'd', 'b'};
    list2.init(data2, sizeof(data2)/sizeof(data2[0]));

    std::cout << std::endl;

    list2.print();
    std::cout << "Is a palindrome " << (list2.isPalindrome() ? "true" : "false") << std::endl;

    return 0;
}