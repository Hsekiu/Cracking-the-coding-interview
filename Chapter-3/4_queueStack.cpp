#include "StackBase.h"
#include "StackBase.cpp"

/*
    To make a Queue using two stacks use one to hold the data and the other as
    temporary storage. When you pop from the inStack and push to the outStack you
    reverse the order. Adding is simple since with the stack you add to the front.
    With remove you have to loop through the stack before the last element and then
    push all the data back.
*/

template<class T>
class myQueue : public StackBase<T> {

    public:

    void init(T n[], int num) {
        inStack.init(n, num);
        size = num;
    }

    void add(int data) {
        inStack.push(data);
        size++;
    }

    T remove() {
        size--;

        //Loop through the stack and push all but the last element to the working stack.
        for(int i = 0; i < size; i++) {
            outStack.push(inStack.pop());
        }
        //Remove the last element.
        T result = inStack.pop();

        //Transfer data back from working stack to data stack.
        for(int i = 0; i < size; i++) {
            inStack.push(outStack.pop());
        }

        return result;
    }

    void print() {
        //When transfering data between stack it reverses them.
        for(int i = 0; i < size; i++) {
            outStack.push(inStack.pop());
        }

         outStack.print();

        //Data stack is now empty have to push all the data back after printing.
        for(int i = 0; i < size; i++) {
            inStack.push(outStack.pop());
        }
    }

    T peek() {
        for(int i = 0; i < size; i++) {
            outStack.push(inStack.pop());
        }

        T result = outStack.peek();

        for(int i = 0; i < size; i++) {
            inStack.push(outStack.pop());
        }

        return result;
    }

    bool isEmpty() {
        return inStack.isEmpty();
    }

	private:

    //Stack to hold the data.
	StackBase<T> inStack;
    //Temp working stack.
    StackBase<T> outStack;
    int size;

};

int main() {

	myQueue<char> queue;
	char data[] = {'a','z','d','e'};
	queue.init(data, sizeof(data)/sizeof(char));
	std::cout << "Queue is: ";
    queue.print();
    std::cout << "Adding y to Queue: ";
    queue.add('y');
    queue.print();
    std::cout << "Removing oldest element: " << queue.remove() << std::endl;
    std::cout << "Removing oldest element: " << queue.remove() << std::endl;
    std::cout << "Queue is: ";
    queue.print();
    std::cout << "Top element is: " << queue.peek() << std::endl;
    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "true" : "false") << std::endl;
	return 0;
}