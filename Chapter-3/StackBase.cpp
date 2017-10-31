#include "StackBase.h"

StackBase::StackBase() {
}

void StackBase::push(int data) {
	addHead(data);
}

int StackBase::pop() {
	if(head == nullptr) {
		throw std::logic_error("Cannot operate on empty Stack.");
	}

	node *tmp = head;
	int result = head->data;
	head = head->next;

	return result;
}

int StackBase::peek() {
	if(head != NULL) {
		return head->data;
	} else {
		 throw std::logic_error("Cannot operate on empty Stack.");
	}
}

void StackBase::print() {
	LinkedListBase::print();
}

bool StackBase::isEmpty() {
	return size == 0;
}