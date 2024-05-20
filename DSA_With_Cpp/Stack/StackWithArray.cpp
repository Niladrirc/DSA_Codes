//
//  main.cpp
//  StackWithArrays
//
//  Created by Niladri Choudhury on 20/05/24.
//

#include <iostream>
using namespace std;

template <class T>
class StackWithArray {
private:
    int s;
    int top;
    T *p;

public:
    StackWithArray(T n) {
        s = n;
        top = -1;
        p = new T[s];
    }

    bool isFull() {
        return (top >= (s-1)) ? true : false;
    }

    bool isEmpty() {
        return (top == -1) ? true : false;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stac is full...cannot enter new element" << endl;
            return;
        }

        top++;
        p[top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack empty" << endl;
            return;
        }

        top--;
    }

    T peek(int pos) {
        if (isEmpty() || (top - pos + 1 < 0)) {
            cout << "Stack is empty..nothing to peek";
        }
        return p[top - pos + 1];

    }

    T stackTop() {
        if (isEmpty()) {
            return -1;
        }
        return p[top];
    }
};



int main(int argc, const char * argv[]) {

    cout << "Enter size of Stack: ";
    int n;

    cin >> n;
    StackWithArray<int> stack(n);
    stack.push(10);
    stack.push(12);
    stack.push(15);
    stack.push(18);
    stack.push(20);
    stack.push(21);

    stack.pop();
    stack.push(21);

    cout << "Element at pos 3: " << stack.peek(3) << endl;

    cout << "Element at stack top: " << stack.stackTop() << endl;



    return 0;
}
