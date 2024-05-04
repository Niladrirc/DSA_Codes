#include <iostream>
using namespace std;


class Node {
public:
    Node *previous;
    int data;
    Node *next;
};

class CircularDoublyLL {
public:
    Node *head;
    
    CircularDoublyLL(int data) {
        Node *temp = new Node;
        temp->data = data;
        temp->next = temp;
        temp->previous = temp;
        
        head = temp;
    }
    
    CircularDoublyLL(int arr[], int n) {
        Node *temp, *q;
        
        temp = new Node;
        temp->data = arr[0];
        temp->previous = temp;
        temp->next = temp;
        q = temp;
        head = temp;
        
        for (int i=1; i<n; i++) {
            temp = new Node;
            temp->data = arr[i];
            temp->next = head;
            temp->previous = q;
            head->previous = temp;
            q->next = temp;
            q = temp;
        }
    }
    
    
    void display() {
        Node *p = head;
        
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        
        cout << endl;
    }
    
    void insert(int pos, int data) {
        Node *temp, *p;
        temp = new Node;
        temp->data = data;
        p = head;

        if (pos == 1) {
            temp->next = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = temp;
            temp->previous = p;
            head->previous = temp;
            
            head = temp;
        } else {
            for (int i=1; i<pos-1; i++) {
                p = p->next;
            }
            temp->next = p->next;
            temp->previous = p;
            p->next = temp;
            temp->next->previous = temp;
        }
    }
    
    void deleteNode(int pos) {
        Node *p = head;
        Node *t;
        if (pos  == 1) {
            while (p->next != head) {
                p = p->next;
            }
            p->next = head->next;
            head->next->previous = p;
            
            delete head;
            head = p->next;
        } else {
            for (int i=1; i<pos-1; i++) {
                p = p->next;
            }
            t = p->next;
            p->next->next->previous = p;
            p->next = p->next->next;
            
            delete t;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    int arr[5] = {10, 20, 30, 40, 50};
    CircularDoublyLL list = CircularDoublyLL(arr, 5);
    list.display();
    
    list.insert(6, 60);
    list.display();
    
    list.insert(1, 00);
    list.display();
    
    list.deleteNode(1);
    list.display();
    
    list.deleteNode(6);
    list.display();
    
    return 0;
}
