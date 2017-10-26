#include <stdio.h>
#include <iostream>

class arrStack {
    
    private:
        int stack[10] = {0};
        int size = 1;
        int middle = 4, head = 0, tail = 9;
        int midPos = 0;
    
    public:
        
        bool isEmpty() {
            return (size == 1);
        }
        
        int pop() {
            if(size != 0) {
                size--;
                return stack[size-1];
            }
            return 0;
        }
        
        void push(int list, int data) {
            if(list == 1) {
                stack[head] = data;
                head++;
            } else if (list == 2) {
                if(midPos < 0) {
                    stack[middle + midPos] = data;
                    std::cout << midPos << std::endl;
                    midPos *= -1;
                } else if (midPos == 0) {
                    stack[middle] = data;
                    midPos = -1;
                } else {
                    stack[middle + midPos] = data;
                    std::cout << midPos << std::endl;
                    midPos *= -1;
                    midPos--;
                }
            } else if (list == 3) {
                stack[tail] = data;
                tail--;
            } else {
                return;
            }
            size++;
        }
        
        void print() {
            for(int i = 0; i < (sizeof(stack)/sizeof(int)); i++) {
                std::cout << stack[i] << ", ";
            }
            std:: cout << std::endl;
        }
};


int main() {
    
    arrStack stack1;
    stack1.push(2, 1);
    stack1.push(2, 2);
    stack1.push(2, 3);
    stack1.push(2, 4);
    stack1.push(1, 5);
    stack1.push(3, 6);
    stack1.print();
    std::cout << (stack1.isEmpty() ? "true" : "false") << std::endl;
    //std::cout << stack1.pop() << std::endl;
    //std::cout << stack1.pop() << std::endl;
    //std::cout << stack1.pop() << std::endl;
    //std::cout << (stack1.isEmpty() ? "true" : "false") << std::endl;
    
    return 0;
}