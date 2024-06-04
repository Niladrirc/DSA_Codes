//
//  main.cpp
//  CircularQueueWithArrays
//
//  Created by Niladri Choudhury on 04/06/24.
//

#include <iostream>

using namespace std;

template<typename T> class CircularQueue {
private:
    int front;
    int rear;
    int size;
    T *q;
public:
    CircularQueue(int size) {
        this->size = size;
        this->front = this->rear = 0;
        this->q = new T[this->size];
    }
    
    bool isEmpty() {
        return (this->front == this->rear);
    }
    
    bool isFull() {
        return (((this->rear + 1) % this->size) == this->front);
    }
    
    T frontElement() {
        if (this->isEmpty()) {
            cout << "Queue is empty..." << endl;
            return NULL;
        }
        return (front+1)%size;
    }
    
    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue is full..." << endl;
            return;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
    }
    
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty..." << endl;
        }
        front = (front + 1) % size;
        return q[front];
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty...Nothing to dispaly";
            return;
        }
        int index = (front + 1) % size;
        cout << "Elements in queue: {";
        do {
            cout << q[index] << ", ";
            index = (index + 1) % size;
        } while (index != ((rear+1)%size));
        cout << "}" << endl;
    }
    
    int queueSize() {
        int count = 0;
        int index = front;
        
        while (index <= rear) {
            index = (index + 1) % size;
            count ++;
        }
        return count;
    }
    
};


int main(int argc, const char * argv[]) {
    
    CircularQueue<int> queue(7);
    
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    
    queue.display();
    cout << "Front Element: " << queue.frontElement();
    
    queue.dequeue();
    queue.display();
    cout << "Front Element: " << queue.frontElement();
    
    queue.enqueue(7);
    queue.display();
    cout << "Front Element: " << queue.frontElement();
    
    
    return 0;
}
