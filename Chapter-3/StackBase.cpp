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
	LinkedListBase::print();
}