#include "StackBase.h"
#include "StackBase.cpp"
#include <vector>

/*
	Using a vector to store the plate struc that consists of the stack and a size value.
	When a new element is added and it is larger then the threshold then a new stack is
	pushed to the back of the vector, when a value is popped and it is the last one then
	the plate is also popped from the back. The problem with the structure is if you pop
	a whole stack from the vector that isn't the last you will get holes in the stack of
	stacks which can lead to errors.
*/

template<class T>
class stackPlates : public StackBase<T> {
    public:

    //Maximum size of each plate structure.
    int threshold;

    //Stack doesn't hold size information thus made a struct to hold the information.
    struct plate {
        StackBase<T> stack;
        int size;
    };

    stackPlates() {
    	stackSet.push_back(plate());
    	threshold = 4;
    }

    void init(T n[], int num) {
    	for(int i = 0; i < num; i++) {
        	push(n[i]);
    	}
	}

    void push(T data) {
    	//Current plate size is lower then threshold thus push to that stack.
    	if(stackSet.back().size < threshold) {
    		stackSet.back().stack.push(data);
    		stackSet.back().size++;
    	} else {
    	//Plate has reached threshold thus make a new plate and push element to it.
    		stackSet.push_back(plate());
    		stackSet.back().stack.push(data);
    		stackSet.back().size++;
    	}
    }

    void print() {
    	for (auto & element : stackSet) {
    		element.stack.print();
		}
    }

    T pop() {
    	//If last element of plate return that element and pop the plate.
    	if(stackSet.back().size <= 1) {
    		T result = stackSet.back().stack.pop();
    		stackSet.pop_back();
    		return result;
    	} else {
    		stackSet.back().size--;
    		return stackSet.back().stack.pop();
    	}
    }

    T pop(int n) {
    	if(stackSet[n].size <= 1) {
    		T result = stackSet[n].stack.pop();
    		stackSet.erase(stackSet.begin() + n);
    		return result;
    	} else {
    		stackSet[n].size--;
    		return stackSet[n].stack.pop();
    	}
    }

	private:

	std::vector<plate> stackSet;

};

int main() {

	stackPlates<int> stack;
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	stack.init(data, sizeof(data)/sizeof(int));
	stack.push(12);
	std::cout << "Stack of stacks is: " << std::endl;
	stack.print();
	std::cout << "Poping last element: " << stack.pop() << std::endl;
	std::cout << "Poping last element: " << stack.pop() << std::endl;
	std::cout << "Poping last element: " << stack.pop() << std::endl;
	std::cout << "Poping last element: " << stack.pop() << std::endl;
	std::cout << "New stack of stack is: " << std::endl;
	stack.print();
	std::cout << "Poping stack 1: " << stack.pop(0) << std::endl;
	std::cout << "New stack of stack is: " << std::endl;
	stack.print();
	return 0;
}