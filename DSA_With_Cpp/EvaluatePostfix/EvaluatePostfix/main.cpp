//
//  main.cpp
//  EvaluatePostfix
//
//  Created by Niladri Choudhury on 03/06/24.
//

#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

class Stack {
public:
    int size;
    int top;
    int *p;
    
    Stack(int size) {
        this->size = size;
        this->top = -1;
        this->p = new int[this->size];
    }
    
    bool isEmpty() {
        return this->top == -1;
    }
    
    bool isFull() {
        return this->top == this->size - 1;
    }
    
    void push(int value) {
        if (this->isFull()) {
            cout << "Stack Overflow!!!" << endl;
            return;
        }
        this->p[++this->top] = value;
    }
    
    int pop() {
        if (this->isEmpty()) {
            cout << "Stack is Empty";
            return -1;
        }
        int temp = this->p[this->top];
        this->p[this->top] = 0;
        this->top -= 1;
        return temp;
    }
    
    int peek(int index) {
        if (isEmpty() || (top - index + 1) < 0) {
            cout << "Invalid Index" << endl;
            return '\0';
        }
        return this->p[this->top - index + 1];
    }
    
    int stackTop() {
        if (this->isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return this->p[this->top];
    }
};


int evaluate(char *exp) {
    int i = 0;
    Stack stk((int) strlen(exp) + 1);
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            stk.push(exp[i++] - '0');
        } else {
            if (stk.peek(2) == '\0' || stk.isEmpty() || stk.top == -1) {
                throw runtime_error("Invalid expression: not enough operands");
            }
            int val2 = stk.pop();
            int val1 = stk.pop();
            
            switch (exp[i]) {
                case '+':
                    stk.push(val1 + val2);
                    break;
                case '-':
                    stk.push(val1 - val2);
                    break;
                case '*':
                    stk.push(val1 * val2);
                    break;
                case '/':
                    stk.push(val1 / val2);
                    break;
                case '^':
                    stk.push(val1^val2);
                    break;
                default:
                    throw runtime_error("Invalid operator");
            }
            
            i++;
        }
    }
    if (stk.isEmpty() || stk.top > 0) {
        throw runtime_error("Invalid expression: too many operands");
    }
    return stk.pop();
}

int main(int argc, const char * argv[]) {
    char *exp = (char *) "35*62/+4-";
    try {
        int result = evaluate(exp);
        cout << "The result of the expression is: " << result << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
