#include <iostream>
using namespace std;

class Node {
public:
    Node *prev;
    int value;
    Node *next;
};

class DoublyLL {
public:
    Node *head;
    Node *last;
    
    DoublyLL(int data) {
        Node *temp = new Node;
        temp->value = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        last = temp;
    }
    
    DoublyLL(int arr[], int n) {
        Node *temp, *p;
        temp = new Node;
        temp->value = arr[0];
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        last = temp;
        
        for (int i=1; i<n; i++) {
            temp = new Node;
            temp->value = arr[i];
            temp->next = NULL;
            temp->prev = last;
            
            last->next = temp;
            last = temp;
        }
    }
    
    void display() {
        Node *p = head;
        while (p != NULL) {
            cout << p->value << " ";
            p = p->next;
        }
        cout  << endl;
    }
    
    void insert(int pos, int data) {
        Node *t, *p;
        if (pos == 0) {
            t = new Node;
            t->value = data;
            t->prev = NULL;
            
            if (head == NULL) {
                t->next = NULL;
                head = t;
            } else {
                t->next = head;
                head = t;
            }
        } else {
            t = new Node;
            t->value = data;
            p = head;
            
            for (int i=0; i<pos-1; i++) {
                p = p->next;
            }
            
            t->prev = p;
            t->next = p->next;
            p->next = t;
        }
    }
    
    void deleteNode(int pos) {
        Node *p;
        if (pos == 1) {
            p = head->next;
            p->prev = NULL;
            delete head;
            head = p;
        } else {
            p = head;
            for (int i=1; i<pos; i++) {
                p = p->next;
            }
            p->prev->next = p->next;
            delete p;
        }
    }
    
    void reverse() {
        Node *p = head;
        while (p != NULL) {
            Node *temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
            
            if (p != NULL && p->next == NULL) {
                head = p;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    DoublyLL list1 = DoublyLL(10);
    list1.display();
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    DoublyLL list2 = DoublyLL(arr, 5);
    list2.display();
    
    
    list2.insert(5, 6);
    list2.display();
    
    list2.insert(0, 0);
    list2.display();
    
    list2.deleteNode(1);
    list2.display();
    
    list2.deleteNode(6);
    list2.display();
    
    list2.reverse();
    list2.display();
    
    return 0;
}
