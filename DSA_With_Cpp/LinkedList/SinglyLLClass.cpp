//
//  main.cpp
//  SinglyLinkedListClass
//
//  Created by Niladri Choudhury on 23/04/24.
//

#include <iostream>
using namespace::std;

class Node {
public:
    int value;
    Node *next;
};


class LinkedList {
private:
    Node *first;
    Node *last;
public:
    LinkedList() {
        first = NULL;
        last = first;
    }
    
    LinkedList(int A[], int n) {
        Node *temp = new Node;
        temp->value = A[0];
        temp->next = NULL;
        first = last = temp;
        
        for (int i=1; i<n; i++) {
            Node *temp = new Node;
            temp->value = A[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
    }
    
    ~ LinkedList() {
        delete first;
    }
    
    void display() {
        Node *p = first;
        while (p!=NULL) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    void recursiveDisplay(Node *p) {
        if (p == NULL) {
            return;
        }
        cout << p->value << " ";
        recursiveDisplay(p->next);
    }
    
    int count() {
        int c = 0;
        Node *p = first;
        while (p != NULL) {
            c ++;
            p = p->next;
        }
        return c;
    }
    
    int recursiveCount(Node *p) {
        if (p == NULL) {
            return 0;
        }
        return 1+recursiveCount(p->next);
    }
    
    int sum() {
        Node *p = first;
        int s = 0;
        while (p!=NULL) {
            s += p->value;
            p = p->next;
        }
        return s;
    }
    
    int searchmax(Node *p) {
        if (p == NULL) {
            return INT32_MIN;
        } else {
            int x = searchmax(p->next);
            if (p->value > x) {
                return p->value;
            } else {
                return x;
            }
        }
    }
    
    Node * search(int key) {
        Node *p = first;
        while (p != NULL) {
            if (p->value == key) {
                return p;
            } else {
                p = p->next;
            }
        }
        return NULL;
    }
    
    void insert(int pos, int value) {
        Node *temp = new Node;
        temp->value = value;
        temp->next = NULL;
        
        int c = this->count();
        
        if (pos == 1) {
            temp->next = first;
            first = temp;
        } else if (2 <= pos <= c+1) {
            
            if (first == NULL) {
                printf("List is empty. Cannot enter at this position");
            }
            
            Node *p = first;
            for (int i=1; i<pos-1; i++) {
                p = p->next;
            }
            
            temp->next = p->next;
            p->next = temp;
            
        } else {
            cout << "List is of size: " << c << " but desired position is: " << pos << ". Please check" << endl;
        }
    }
    
    bool checkSorting() {
        Node *lp = first;
        Node *tp = new Node;
        tp->value = INT32_MIN;
        tp->next = NULL;
        
        
        while (lp != NULL) {
            if (tp->value > lp->value) {
                return false;
            }
            tp = lp;
            lp = lp->next;
        }
        return true;
    }
    
    void removeDuplicates() {
        cout << "Will only delete consecutive duplicate nodes" << endl;
        
        Node *lp = first;
        Node *tp = new Node;
        tp->value = INT32_MIN;
        tp->next = NULL;
        
        while (lp != NULL) {
            if (tp->value == lp->value) {
                tp->next = lp->next;
                delete lp;
                lp = tp->next;
            } else {
                tp = lp;
                lp = lp->next;
            }
        }
    }
    
    void reverseElements() {
        int c = this->count();
        int A[c];
        
        A[0] = 0;
        int i=0;
        Node *p = first;
        
        while (p != NULL) {
            A[i++] = p->value;
            p = p->next;
        }
        
        p = first;
        while (p!=NULL) {
            p->value = A[--i];
            p = p->next;
        }
    }
    
    void reverseLinks() {
        Node *p = first;
        Node *q = NULL;
        Node *r = NULL;
        
        while (p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        first = q;
    }
    
    void concat(LinkedList list) {
        Node *p = first;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << list.first;
        p->next = list.first;
    }
    
    void merge(LinkedList list)  {
        if (this->checkSorting() && list.checkSorting()) {
            Node *p = this->first;
            Node *q = list.first;
            Node *r = new Node;
            Node *s = new Node;
            
            if (p->value < q->value) {
                r = s = p;
                p = p->next;
            } else {
                r = s = q;
                q = q->next;
            }
            
            while (p != NULL && q != NULL) {
                if (p->value < q->value) {
                    s->next = p;
                    s = p;
                    p = p->next;
                } else {
                    s->next = q;
                    s = q;
                    q = q->next;
                }
            }
            
            if (p != NULL) {
                s->next = p;
            } else {
                s->next = q;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    LinkedList A = LinkedList();
    
    A.insert(1, 2);
    A.insert(2, 4);
    A.insert(3, 6);
    A.insert(4, 6);
    A.insert(5, 8);
    A.display();
    
    A.removeDuplicates();
    A.display();
    
    int arr[5] = {1,3,5,7,9};
    LinkedList B = LinkedList(arr, 5);
    
    B.display();
    
    A.concat(B);
    A.display();
    
    return 0;
}
