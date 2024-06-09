//
//  main.cpp
//  QueueUsingLinkedList
//
//  Created by Niladri Choudhury on 06/06/24.
//

#include <iostream>

using namespace std;

template <typename T> class Node {
public:
    T data;
    Node<T> *next;
};

template <typename T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;
    
public:
    Queue() {
        front = rear = NULL;
    }
    
    Queue(T value) {
        Node<T> newNode = new Node<T>;
        front = rear = newNode;
    }
    
    bool isEmpty() {
        return (front == NULL);
    }
    
    bool isFull() {
        Node<T> *temp = new Node<T>;
        
        if (temp == NULL) {
            return true;
        } else {
            delete temp;
            return false;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue empty...Nothing to display..." << endl;
            return;
        }
        
        Node<T> *temp = front;
        cout << "Queue elements... \n{" ;
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "}" << endl;
    }
    
    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue is full...No space in heap" << endl;
            return;
        }
        
        Node<T> *temp = new Node<T>;
        temp->data = value;
        temp->next = NULL;
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue already empty...Nothing to delete..." << endl;
            return NULL;
        }
        Node<T> *t = front;
        T data = t->data;
        front = front->next;
        delete t;
        return data;
    }
    
    T frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty..." << endl;
        }
        
        return front->data;
    }
    
    int queueSize() {
        Node<T> *t = front;
        int count = 0;
        while (t != NULL) {
            count += 1;
            t = t->next;
        }
        return count;
    }
};


int main(int argc, const char * argv[]) {
    
    Queue<int> queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    queue.display();
    cout << "Queue size: " << queue.queueSize() << endl;
    
    queue.dequeue();
    
    queue.display();
    cout << "Queue size: " << queue.queueSize() << endl;
    return 0;
}
