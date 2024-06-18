//
//  main.cpp
//  TreeBasic
//
//  Created by Niladri Choudhury on 17/06/24.
//

#include <iostream>

using namespace std;

class TreeNode {
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    
    TreeNode(int value): data(value), left(nullptr), right(nullptr) {}
};

class QueueNode {
public:
    QueueNode *next;
    TreeNode *data;
    
    QueueNode(TreeNode *address): data(address), next(nullptr) {
};

class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public:
    
    Queue() {
        front = rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    
    void enqueue(TreeNode *address) {
        QueueNode *temp = new QueueNode(address);
        
        if (temp == NULL) {
            cout << "Queue is full !!" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    
    TreeNode * dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.." << endl;
            return nullptr;
        }
        
        TreeNode *temp = front->data;
        QueueNode *oldFront = front;
        front = front->next;
        delete oldFront;
        return temp;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.." << endl;
            return;
        }
        
        QueueNode *temp = front;
        cout << "Elements of the queue are: " << endl;
        while (temp != nullptr) {
            cout << "Address: " << temp->data << " | Value: " << temp->data->data << endl;
            temp = temp->next;
        }
    }
};


class Tree {
public:
    Queue queue;
    TreeNode *root;
    
    Tree() : root(nullptr) {}
    
    void create() {
        TreeNode *q, *t;
        int x;
        
        cout << "Enter root value: " << endl;
        cin >> x;
        
        root = new TreeNode(x);
        queue.enqueue(root);
        
        while (!queue.isEmpty()) {
            q = queue.dequeue();
            
            cout << "Enter left child of " << q->data << " : " << endl;
            cin >> x;
            
            if (x != -1) {
                t = new TreeNode(x);
                
                q->left = t;
                queue.enqueue(t);
            }
            
            cout << "Enter right child of " << q->data << " : " << endl;
            cin >> x;
            
            if (x != -1) {
                t = new TreeNode(x);
                
                q->right = t;
                queue.enqueue(t);
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    
    Tree tree;
    tree.create();
    
    return 0;
};
