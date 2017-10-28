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

int StackBase::peek() {
	if(head != NULL) {
		return head->data;
	} else {
		return 0;
	}
}

void StackBase::print() {
	LinkedListBase::print();
}