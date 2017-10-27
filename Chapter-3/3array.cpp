#include <stdio.h>
#include <iostream>
#include <math.h>

class arrStack {
    
    private:
        int stack[10];
        int s1head;
        int s2head;
        int s3head;
        int middle;
        float midCons;
    
    public:

        void init() {
            for(int i = 0; i < (sizeof(stack)/sizeof(int)); i++) {
                stack[i] = 0;
            }
            s1head = 0;
            s2head = 4;
            s3head = 9;
            middle = 4;
            midCons = 0;
        }
        
        bool isEmpty(int list) {
            if(list == 1) {
                return (s1head == 0);
            } else if(list == 2) {
                return (s2head == 4);
            } else if (list == 3) {
                return (s3head == 9);
            } else {
                return 0;
            }
        }
        
        int pop(int list) {
            int tmp;
            if(list == 1) {
                tmp = stack[s1head - 1];
                stack[s1head - 1] = 0;
                s1head--;
                return tmp;
            } else if(list == 2) {
                int midPos;
                midCons -= 0.5;
                if(ceil(midCons) == midCons) {
                    midPos = midCons;  
                } else {
                    midPos = -1*ceil(midCons);
                }
                tmp = stack[middle + midPos];
                stack[middle + midPos] = 0;
                return tmp;
            } else if(list == 3) {
                tmp = stack[s3head + 1];
                stack[s3head + 1] = 0;
                s3head++;
                return tmp;
            } else {
                return 0;
            }
        }
        
        void push(int list, int data) {
            if(list == 1) {
                stack[s1head] = data;
                s1head++;
            } else if (list == 2) {
                int midPos;
                if(ceil(midCons) == midCons) {
                    midPos = midCons;  
                } else {
                    midPos = -1*ceil(midCons);
                }
                midCons += 0.5;
                stack[middle + midPos] = data;
                s2head = middle + midPos;
            } else if (list == 3) {
                stack[s3head] = data;
                s3head--;
            } else {
            }
        }
        
        int peek(int list) {
            if(list == 1) {
                return stack[s1head - 1];
            } else if (list == 2) {
                return stack[s2head];
            } else if (list == 3) {
                return stack[s3head + 1];
            } else {
                return 0;
            }
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
    stack1.init();
    stack1.push(2, 1);
    stack1.print();
    stack1.push(2, 2);
    stack1.print();
    stack1.push(2, 3);
    stack1.print();
    stack1.push(2, 4);
    stack1.print();
    stack1.push(1, 5);
    stack1.print();
    stack1.push(3, 6);
    stack1.print();
    stack1.push(3, 99);
    stack1.print();

    std::cout << "Top of stack 1 is: " << stack1.peek(1) << std::endl;
    std::cout << "Top of stack 2 is: " << stack1.peek(2) << std::endl;
    std::cout << "Top of stack 3 is: " << stack1.peek(3) << std::endl;
    std::cout << (stack1.isEmpty(1) ? "true" : "false") << std::endl;
    std::cout << stack1.pop(1) << std::endl;
    std::cout << stack1.pop(2) << std::endl;
    std::cout << stack1.pop(3) << std::endl;
    std::cout << stack1.pop(2) << std::endl;
    stack1.print();
    
    return 0;
}