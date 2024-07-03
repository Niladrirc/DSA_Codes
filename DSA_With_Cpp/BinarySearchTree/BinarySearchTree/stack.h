//
//  stack.h
//  BinarySearchTree
//
//  Created by Niladri Ray Choudhury on 30/06/24.
//

#ifndef stack_h
#define stack_h
#include "Nodes.h"

using namespace std;

class Stack {
    Node *top;
    
public:
    bool isEmpty() {
        return (top == nullptr);
    }
    
    void push(TreeNode *add) {
        Node *p = new Node(add);
        if (top == nullptr) {
            top = p;
            return;
        }
        p->next = top;
        top = p;
    }
    
    TreeNode * pop() {
        if (isEmpty()) {
            cout << "Stack is empty.." << endl;
            return nullptr;
        }
        
        Node *t = top;
        top = top->next;
        TreeNode *p = t->address;
        delete t;
        return p;
    }
    
    TreeNode * getTop() {
        if (isEmpty()) {
            cout << "Nothing to see here..." << endl;
            return nullptr;
        }
        return top->address;
    }
};

#endif /* stack_h */
