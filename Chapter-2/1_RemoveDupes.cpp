#include <stdio.h>
#include <iostream>
#include <unordered_map>

class LinkedList {

public:

    struct node {
        int data;
        node *next;
    };
    
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addVal(int n) {
        node *NewNode = new node();
        NewNode->data = n;
        NewNode->next = NULL;
        
        if(tail == NULL) {
            head = NewNode;
        } else {
            tail->next = NewNode;
        }
        tail = NewNode;
        size++;
    }
    
    void print() {
        node *tmp = head;
        while(tmp != nullptr) {
            std::cout << "," << tmp->data;
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    
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
    
private:
    node *head;
    node *tail;
};

int main() {
    LinkedList list;
    
    list.addVal(5);
    list.addVal(10);
    list.addVal(15);
    list.addVal(5);
    list.addVal(1);
    list.addVal(4);
    
    list.print();
    list.removeDupe();
    list.print();

    return 0;
}