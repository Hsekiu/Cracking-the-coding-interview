#include "StackBase.h"

/*
	Keep another stack that is updated alongside the data stack but consists of the
	minimum at that point of the stack. If a new minimum appears add it to the minstack
	otherwise add the old min to the min stack since that minimum is still the lowest
	one at that point.
*/

class minStack : public StackBase {
    public:

    void push(int data) {
    	stack.StackBase::push(data);
    	//If new element is new minimum add it to min stack if not add old min to minstack.
    	if(!isEmpty()) {
    		if(data < minStack.peek() || minStack.peek() == 0) {
    			minStack.StackBase::push(data);
    		} else {
    			minStack.StackBase::push(minStack.peek());
    		}
    	} else {
    		minStack.StackBase::push(data);
    	}
    	
    }

    void print() {
    	stack.StackBase::print();
    	minStack.StackBase::print();
    }

    int pop() {
    	minStack.pop();
    	return stack.pop();
    }

    int getMin() {
    	return minStack.peek();
    }

	private:

	StackBase stack;
	//Stack of mins at those positions in stack.
	StackBase minStack;
};

int main() {

	minStack stack;
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