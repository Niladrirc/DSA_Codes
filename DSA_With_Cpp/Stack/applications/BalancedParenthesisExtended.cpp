//
//  main.cpp
//  ParenthesisMatching
//
//  Created by Niladri Choudhury on 23/05/24.
//

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;
};

class Stack {
private:
    Node *top;
    
public:
    Stack() {
        top = NULL;
    }
    
    bool isEmpty() {
        return (top==NULL) ? true : false;
    }
    
    bool isFull() {
        Node *temp = new Node;
        return (temp == NULL) ? true : false;
    }
    
    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!!!" << endl;
        }
        Node *temp = new Node;
        temp->next = top;
        temp->data = c;
        top = temp;
        
        cout << "Successfully pushed " << c << " into the stack." << endl;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack already empty. Nothing to pop.." << endl;
        }
        Node *temp = top;
        top = top->next;
        cout << "Successfully popped " << temp->data << " from Stack." << endl;
        
        delete temp;
    }
    
    void toString() {
        if (isEmpty()) {
            cout << "Stack empty.." << endl;
        }
        Node *temp = top;
        cout << "Elements in the stack" << endl;
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
    }
    
    char getStackTop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return NULL;
        }
        return top->data;
    }
};

int main(int argc, const char * argv[]) {
    string exp = "{((a + b] * [c - d]) / e}";
    char *c = new char[exp.length()];
    strcpy(c, exp.c_str());
    
    Stack stk;
    
    for (int i=0; i<exp.length(); i++) {
        if (c[i] == '(' || c[i] == '{' || c[i] == '[') {
            stk.push(c[i]);
        } else if (c[i] == ')') {
            char temp = stk.getStackTop();
            if (temp != NULL && temp == '(') stk.pop();
        } else if (c[i] == '}') {
            char temp = stk.getStackTop();
            if (temp != NULL && temp == '{') stk.pop();
        } else if (c[i] == ']') {
            char temp = stk.getStackTop();
            if (temp != NULL && temp == '[') stk.pop();
        }
            
        
    }
    
    if (stk.isEmpty()) {
        cout << "Parenthesis are balanced." << endl;
    } else {
        cout << "Parenthesis are not balanced." << endl;
    }
    
    return 0;
}
