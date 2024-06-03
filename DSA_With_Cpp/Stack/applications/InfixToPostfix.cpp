//
//  main.cpp
//  InfixToPastfixFinal
//
//  Created by Niladri Choudhury on 01/06/24.
//

#include <iostream>
#include <cctype>
#include <sstream>


using namespace std;


class Stack {

public:
    int size;
    int top;
    char *p;
    
    Stack(int size) {
        this->size = size;
        top = -1;
        p = new char[this->size];
    }
    
    bool isEmpty() {
        return (this->top == -1);
    }
    
    bool isFull() {
        return (this->top == (this->size)-1);
    }
    
    void push(int value) {
        if (this->isFull()) {
            cout << "Stack overflow..." << endl;
        }
        this->top += 1;
        this->p[this->top] = value;
        
    }
    
    void pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow.." << endl;
        }
        
        int x = this->p[this->top];
        this->p[this->top] = 0;
        this->top--;
        
    }
    
    int getStackTop() {
        return this->top;
    }
    
    char peek(int index) {
        if (this->isEmpty() || ((this->top - index + 1) > 0)) {
            cout << "Invalid Index.\nTry again" << endl;
            return '\0';
        }
        return this->p[this->top - index + 1];
    }
};

int outPrecedence(char c) {
    if (c=='+' || c=='-') {
        return 1;
    } else if (c=='*' || c=='/') {
        return 3;
    } else if (c == '^') {
        return 6;
    } else if (c == '(') {
        return 7;
    } else if (c == ')') {
        return 0;
    }
    
    return -1;
}


int inPrecedence(char c) {
    if (c=='+' || c=='-') {
        return 2;
    } else if (c=='*' || c=='/') {
        return 4;
    } else if (c == '^') {
        return 5;
    } else if (c == '(') {
        return 0;
    }
    return -1;
}


char * convert(char *infixExp) {
    int expLength = (int) strlen(infixExp) + 1;
    
    Stack stk(expLength);
    int i=0, j=0;
    char *postficExp = new char[(int) strlen(infixExp) + 1];
    while (infixExp[i] != '\0') {
        if (isblank(infixExp[i])) {
            i++;
            continue;
        }
        if (isalpha(infixExp[i])) {
            postficExp[j++] = infixExp[i++];
        } else {
            if (stk.isEmpty()) {
                stk.push(infixExp[i++]);
            } else {
                if (outPrecedence(infixExp[i]) > inPrecedence(stk.p[stk.top])) {
                    stk.push(infixExp[i++]);
                } else {
                    if (infixExp[i] == ')') {
                        if (stk.p[stk.top] == '(') {
                            stk.pop();
                            i++;
                        } else {
                            postficExp[j++] = stk.p[stk.top];
                            stk.pop();
                        }
                    } else {
                        postficExp[j++] = stk.p[stk.top];
                        stk.pop();
                        i++;
                    }
                }
            }
        }
    }
    
    while (!stk.isEmpty()) {
        postficExp[j++] = stk.p[stk.top];
        stk.pop();
        i++;
    }
    return postficExp;
}

int main(int argc, const char * argv[]) {
    
    char *infixExp = (char *) "((a + b) * c) - d ^ e ^ f";
    
    cout << "Infix Expression: " << infixExp << endl;
    
    char *postfixExp = convert(infixExp);
    
    cout << "Corresponding Postfix Expression: " << postfixExp << endl;
    
    
    return 0;
}
