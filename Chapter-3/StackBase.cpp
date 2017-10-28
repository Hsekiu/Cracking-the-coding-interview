#include "StackBase.h"

StackBase::StackBase() {
}

void StackBase::push(int data) {
	addHead(data);
}

int StackBase::pop() {
	node *tmp = head;
	int result = head->data;
	head = head->next;

	return result;
}

void StackBase::print() {
	node *tmp = head;
    while(tmp != nullptr) {
        std::cout << "," << tmp->data;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}