#include "StackBase.h"

StackBase::StackBase() {
}

void StackBase::init(int n[], int num) {
    for(int i = 0; i < num; i++) {
        addHead(n[i]);
    }
}

void StackBase::push(int data) {
	addHead(data);
}

int StackBase::pop() {
	if(head == nullptr) {
		throw std::logic_error("Cannot pop an empty Stack.");
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
		 throw std::logic_error("Cannot peek an empty Stack.");
	}
}

bool StackBase::isEmpty() {
	return head == nullptr;
}