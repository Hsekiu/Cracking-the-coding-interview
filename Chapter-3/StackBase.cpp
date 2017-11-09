#include "StackBase.h"

template<class T>
StackBase<T>::StackBase() {
}

template<class T>
void StackBase<T>::init(T n[], int num) {
    for(int i = 0; i < num; i++) {
        addHead(n[i]);
    }
}

template<class T>
void StackBase<T>::push(T data) {
	addHead(data);
}

template<class T>
T StackBase<T>::pop() {
	if(LinkedListBase<T>::head == nullptr) {
		throw std::logic_error("Cannot pop an empty Stack.");
	}

	typename LinkedListBase<T>::node *tmp = LinkedListBase<T>::head;
	int result = LinkedListBase<T>::head->data;
	LinkedListBase<T>::head = LinkedListBase<T>::head->next;

	return result;
}

template<class T>
T StackBase<T>::peek() {
	if(LinkedListBase<T>::head != NULL) {
		return LinkedListBase<T>::head->data;
	} else {
		 throw std::logic_error("Cannot peek an empty Stack.");
	}
}

template<class T>
bool StackBase<T>::isEmpty() {
	return LinkedListBase<T>::head == nullptr;
}