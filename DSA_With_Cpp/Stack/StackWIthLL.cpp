//
//  main.cpp
//  StackWithLL
//
//  Created by Niladri Choudhury on 20/05/24.
//

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;
};

class StackWithLL {
private:
    Node *top;
public:
    StackWithLL() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL) ? true : false;
    }

    bool isFull() {
        Node *temp = new Node;
        if (temp == NULL) {
            return true;
        }
        return false;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow.." << endl;
        }

        Node *temp = new Node;
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty ... nothing to pop" << endl;
        }

        Node *temp = top;
        top = top->next;

        cout << temp->data << "deleted" << endl;
        delete temp;
    }

    int peek(int pos) {
        int count = 1;
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        Node *temp = top;
        while (temp != NULL) {
            if (count == pos) {
                return temp->data;
            }
            temp = temp->next;
            count++;
        }

        cout << "Invalid Position" << endl;
        return -1;
    }
};

int main(int argc, const char * argv[]) {

    StackWithLL stack;

    stack.push(10);
    stack.push(12);
    stack.push(15);
    stack.push(18);
    stack.push(20);

    stack.pop();
    stack.push(20);

    cout << "Value at position 3: " << stack.peek(3) << endl;
    return 0;
}
