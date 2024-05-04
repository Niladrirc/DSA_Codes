//
//  main.cpp
//  StackADT
//
//  Created by Niladri Choudhury on 04/05/24.
//

#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    int *arr;
};

Stack * initialize(Stack *stk) {
    cout << "Enter stack size: ";
    cin >> stk->size;
    stk->top = -1;
    stk->arr = new int[stk->size];
    
    return stk;
}

bool isEmpty(Stack *stk) {
    if (stk->top == -1)
        return true;
    else
        return false;
}

bool isFull(Stack *stk) {
    if (stk->top == (stk->size-1)) {
        return true;
    } else return false;
}

void push(Stack *stk, int value) {
    if (isFull(stk)) {
        cout << "Stack Overflow";
    } else {
        stk->top++;
        stk->arr[stk->top] = value;
    }
}

int pop(Stack *stk) {
    int x = -1;
    if (isEmpty(stk)) {
        cout << "stack underflow";
    } else {
        x = stk->arr[stk->top];
        stk->arr[stk->top] = 0;
        stk->top--;
    }
    return x;
}

int peek(Stack *stk, int pos) {
    if (stk->top - pos + 1 < 0)
        cout << "Invalid Postition sought" << endl;
        return -1;
    else
        return stk->arr[stk->top - pos + 1];
}

int stackTop(Stack *stk) {
    if (isEmpty(stk))
        return -1;
    else
        return stk->arr[stk->top];
}

int main(int argc, const char * argv[]) {
    
    Stack *stk = new Stack;
    stk = initialize(stk);
    
    
    return 0;
}
