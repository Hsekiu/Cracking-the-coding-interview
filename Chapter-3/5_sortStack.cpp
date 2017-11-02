#include "StackBase.h"

/*
    Use two stacks one to hold all the data while doing the equivalent of a insertion sort.
    After insertion is done pop all the data and push to the stack from the temp stack.
*/

class sortStack : public StackBase {
    public:

    void push(int data) {
        //Pushing to empty stack.
        if(stack.isEmpty()) {
            stack.push(data);  
        } else {
            //
            if(stack.peek() > data) {
                stack.push(data);
            //Pushing to rest ofo stack.
            } else {
                StackBase temp;
                bool done = true;
                //Inserting loop.
                while(!stack.isEmpty() && done) {
                    if(stack.peek() > data) {
                        stack.push(data);
                        done = false;
                    }
                    temp.push(stack.pop());
                }
                if(done) {
                    stack.push(data);
                }
                //Transfer back to stack from temp stack.
                while(!temp.isEmpty()) {
                    stack.push(temp.pop());
                }
            }    
        }
    }

    void print() {
        stack.print();
    }

    private:

    StackBase stack;
};

int main() {

    sortStack stack;
    stack.push(3);
    stack.push(1);
    stack.push(2);
    stack.push(6);
    stack.push(9);
    stack.push(1);
    stack.push(4);
    stack.push(8);
    stack.push(2);
    std::cout << "Sort Stack is: ";
    stack.print();
    return 0;
}