//
//  main.cpp
//  QueueUsingArray
//
//  Created by Niladri Choudhury on 03/06/24.
//

#include <iostream>

using namespace std;

template <typename T> class Queue {
    
public:
    int size;
    int front;
    int rear;
    T *q;
    
    Queue(int size) {
        this->size = size;
        this->front = this->rear = -1;
        this->q = new T[this->size];
    }
    
    bool isEmpty() {
        return (this->front == this->rear);
    }
    
    bool isFull() {
        return (this->rear == this->size - 1);
    }
    
    void enqueue(T value) {
        if (this->isFull()) {
            cout << "Queue is Full";
            return;
        }
        this->q[++this->rear] = value;
    }
    
    T dequeue() {
        if (this->isEmpty()) {
            cout << "Queue is empty";
            return NULL;
        }
        this->front += 1;
        return this->q[this->front];
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty...Nothing to dispaly";
            return;
        }
        int index = this->front;
        cout << "Elements in queue: {";
        while (index < this->rear) {
            cout << this->q[++index] << ", ";
        }
        cout << "}" << endl;
    }
    
    T frontElement() {
        if (this->isEmpty()) {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        int index = this->front + 1;
        return this->q[index];
    }
    
    int queueSize() {
        return (this->rear - this->front);
    }
};

int main(int argc, const char * argv[]) {
    
    Queue<int> queue(10);
    
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(14);
    
    queue.display();
    cout << "Front element of the queue: " << queue.frontElement() << endl;
    
    cout << "Queue size: " << queue.queueSize() << endl;
    
    queue.dequeue();
    queue.dequeue();
    
    queue.display();
    cout << "Front element of the queue: " << queue.frontElement() << endl;
    
    cout << "Queue size: " << queue.queueSize() << endl;
    
    return 0;
}
