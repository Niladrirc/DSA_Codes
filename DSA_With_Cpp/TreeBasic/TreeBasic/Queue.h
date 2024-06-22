//
//  Queue.h
//  TreeBasic
//
//  Created by Niladri Choudhury on 20/06/24.
//

#ifndef Queue_h
#define Queue_h
#include "QueueNodeCpp.h"
#include "TreeNodeCpp.h"
using namespace std;

class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
    TreeNode *data;
    
public:
    Queue(): front(nullptr), rear(nullptr), data(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    
    void enqueue(TreeNode *p) {
        QueueNode *temp = new QueueNode(p);
        if (temp == nullptr) {
            cout << "Queue/Heap is Full..." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }
    
    TreeNode * dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty..." << endl;
            return nullptr;
        } else {
            QueueNode *temp = front;
            front = front->next;
            TreeNode *data = temp->data;
            delete temp;
            return data;
        }
    }
    
    TreeNode * peek() {
        return front->data;
    }
    
    int size() {
        int count = 0;
        if (isEmpty()) {
            cout << "Queue is empty";
        } else {
            QueueNode *temp = front;
            while (temp != nullptr) {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        } else {
            QueueNode *t = front;
            while (t != nullptr) {
                cout << "Queue Address: " << t << " | TreeNode Address: " << t->data << " | Tree Node value: " << t->data->data;
                t = t->next;
            }
        }
    }
    
};

#endif /* Queue_h */
