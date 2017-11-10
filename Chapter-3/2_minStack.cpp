#include "StackBase.h"
#include "StackBase.cpp"

/*
	Keep another stack that is updated alongside the data stack but consists of the
	minimum at that point of the stack. If a new minimum appears add it to the minstack
	otherwise add the old min to the min stack since that minimum is still the lowest
	one at that point.
*/

template<class T>
class minStack : public StackBase<T> {
    public:

    void push(T data) {
    	stack.push(data);
    	//If new element is new minimum add it to min stack if not add old min to minstack.
    	if(!minStack.isEmpty()) {
    		if(data < minStack.peek() || minStack.peek() == 0) {
    			minStack.push(data);
    		} else {
    			minStack.push(minStack.peek());
    		}
    	} else {
    		minStack.push(data);
    	}
    	
    }

    void print() {
        std::cout << "Stack is: ";
    	stack.LinkedListBase<T>::print();
        std::cout << "Stack of mins is: ";
    	minStack.LinkedListBase<T>::print();
    }

    T pop() {
    	minStack.pop();
    	return stack.pop();
    }

    T getMin() {
    	return minStack.peek();
    }

	private:

	StackBase<T> stack;
	//Stack of mins at those positions in stack.
	StackBase<T> minStack;
};

int main() {

	minStack<int> stack;
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.push(2);
	stack.push(8);
	stack.print();
	stack.getMin();
	std::cout << "Stack min is: " << stack.getMin() << std::endl;
	std::cout << "Stack pop is: " << stack.pop() << std::endl;
	std::cout << "Stack pop is: " << stack.pop() << std::endl;
	std::cout << "Stack min is: " << stack.getMin() << std::endl;
	stack.print();

	return 0;
}