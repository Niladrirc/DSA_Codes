//
//  main.cpp
//  CircularLinkedListClass
//
//  Created by Niladri Choudhury on 25/04/24.
//

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
};


class CircularLinkedList {
private:
    Node *head;
public:
    CircularLinkedList() {
        Node *temp = new Node;
        head = temp;
    }
    
    CircularLinkedList(int arr[], int n) {
        Node *temp, *last;
        head = new Node;
        head->value = arr[0];
        head->next = head;
        last = head;
        
        for (int i=1; i<n; i++) {
            temp = new Node;
            temp->value = arr[i];
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }
    
    void display() {
        
        Node *p = head;
        do {
            cout << p->value;
            p = p->next;
        } while (p != head);
        cout << endl;
    }
    
    void recursiveDisplay(Node *p) {
        
        static int flag = 0;
        if (p != head || flag == 0) {
            cout << p->value << " ";
            recursiveDisplay(p->next);
        }
        
        flag = 0;
        cout << endl;
    }
    
    int count() {
        Node *p = head;
        int sum = 0;
        do {
            sum++;
        } while (p != head);
        
        return sum;
    }
    
    // void insert(int value, int pos) {
    //     Node *temp = new Node;
    //     temp->value = value;
    //     Node *p = head;
    //     int c = count();
        
    //     if (pos < 1) {
    //         temp->next = head;
    //         if (head == NULL) {
    //             head = temp;
    //             head->next = head;
    //         } else  {
    //             do {
    //                 p = p->next;
    //             } while (p->next != head);
    //             p->next = temp;
    //             head = temp;
    //         } else if (1 <= pos <= c) {
    //             for (int i=0; i< pos-1; i++) {
    //                 p = p->next;
    //             }
    //             temp->next = p->next;
    //             p->next = temp;
    //         } else {
    //             cout << "Wrong entry location provided!!" << endl;
    //         }
    //     }
    // }
    
    void deleteNode(int pos) {
        Node *p, *q;
        if (pos == 1) {
            p = head;
            while (p->next != head) {
                p = p->next;
            }
            if (p == head) {
                delete head;
                head = NULL;
            } else {
                p->next = head->next;
                delete head;
                head = p->next;
            }
        } else {
            p = head;
            for (int i=0; i<pos-2; i++) {
                p = p->next;
            }
            q = p->next;
            delete q;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
