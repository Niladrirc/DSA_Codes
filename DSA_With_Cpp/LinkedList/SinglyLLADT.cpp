//
//  main.cpp
//  SinglyLinkedLists
//
//  Created by Niladri Choudhury on 31/03/24.
//

#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
}*first = NULL, *last = NULL;

struct Node * create(int A[], int n)
{
    struct Node *temp;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->value = A[0];
    first->next = NULL;
    last = first;
    
    for (int  i=1; i<n; i++) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->value = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    
    return first;
}

void display(struct Node *p)
{
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void recursiveDisplay(struct Node *p)
{
    if (p == NULL)
        return;
    
    printf("%d, ", p->value);
    p = p->next;
    recursiveDisplay(p);
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    
    return count;
}

int recursiveCount(struct Node *p)
{
    if (p == NULL)
        return 0;
    
    return recursiveCount(p->next) + 1;
}

int sum(struct Node *p)
{
    if (p == NULL) {
        return 0;
    }
    
    return  p->value + sum(p->next);
}

int max(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT32_MIN;
    
    x = max(p->next);
    return (x > p->value)?x:p->value;
}

struct Node* search(struct Node *p, int element)
{
    while (p != NULL) {
        if (p->value == element) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node* recursiveLinearSearch(struct Node *p, int element) {
    if (p == NULL) {
        return p;
    }
    
    struct Node *temp = recursiveLinearSearch(p->next, element);
    if (temp != NULL)
        return temp;
    
    if (p->value == element) {
        return p;
    } else {
        return NULL;
    }
    
}

void insert(struct Node *list, struct Node *newNode, int pos)
{
    int c = count(list);
    if (pos == 1) {
        // Insert at 1st position i.e. at Start
        newNode->next = list;
        first = newNode;
    } else if (pos == c + 1) {
        while (list->next != NULL) {
            list = list->next;
        }
        newNode->next = NULL;
        list->next = newNode;
        
    } else if (1<pos<=c) {
        int x = 1;
        while (x<pos-1) {
            list = list->next;
            x++;
        }
        newNode->next = list->next;
        list->next = newNode;
    } else {
        printf("Invalid position to enter");
    }
    
}

Node * insertNew(Node *list, int pos, int value) {
    Node *temp = new Node;
    temp->value = value;
    temp->next = NULL;
    
    Node *p = list;
    
    int c = count(list);

    if (pos == 1) {
        temp->next = list;
        list = temp;
        return list;
    } else if (1 < pos <= c) {
        
        if (list == NULL) {
            printf("List is empty. Cannot enter at this position");
            return list;
        }

        for (int i=1; i<pos-1; i++) {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;

        return list;

    } else {
        cout << "List is empty";
        return list;
    }
}

void insertLast(Node *list, int value) {
    Node *temp = new Node;
    temp->value = value;
    temp->next = NULL;
    
    if (list == NULL) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

void sortedListInsert(int value) {
    int min = INT16_MIN + 1;
    Node *t = new Node;
    t->value = value;
    t->next = NULL;
    
    Node *lp = first;
    Node *tp = new Node;
    tp->value = min;
    tp->next = first;
    
    while (lp != NULL) {
        if ((lp->value < value) && (tp->value < value)) {
            lp = lp->next;
            tp = tp->next;
        } else if ((lp->value > value) && (tp->value < value)) {
            tp->next = t;
            t->next = lp;
            return;
        }
    }
}


void deleteNode(int element) {
    // First node to be deleted
    if (first->value == element) {
        Node *p = first;
        first = first->next;
        cout << p->value << " deleted" << endl;
        delete p;
        return;
    } else {
        Node *lp = first;
        Node *tp = new Node;
        
        while (lp != NULL) {
            // we have reached Node to be deleted
            if (lp->value == element) {
                tp->next = lp->next;
                cout << lp->value << " deleted" << endl;
                delete lp;
                return;
            }
            tp = lp;
            lp = lp->next;
        }
    }
    cout << element << " not found" << endl;
}

bool checkListSorting(Node *list) {
    Node *p = list;
    int previousValue = INT32_MIN;
    
    while (p != NULL) {
        if (previousValue < p->value) {
            previousValue = p->value;
            p = p->next;
        } else {
            cout << "List is not sorted..." << endl;
            return false;
        }
    }
    cout << "List is sorted" << endl;
    return true;
}

void removeDuplicates(Node *list) {
    Node *leading = list;
    Node *trailing = new Node;
    
    while (leading != NULL) {
        if (leading->value == trailing->value) {
            trailing->next = leading->next;
            cout << "Removing " << leading->value << " as duplicate." << endl;
            delete leading;
            leading = trailing->next;
        } else {
            trailing = leading;
            leading = leading->next;
        }
    }
}

void reverseLinks(Node *list) {
    // Take 3 pointer for sliding
    Node *p = list;
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

void recursiveReverse(Node *q, Node *p) {
    if (p != NULL) {
        recursiveReverse(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

Node * concat(Node *l1, Node *l2) {
    Node *p = l1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = l2;
    
    return l1;
}

Node * mergeList(Node *first, Node *second) {
    Node *third;
    Node *last;
    if (first->value < second->value) {
        third = last = first;
        first = first->next;
        last->next = NULL;
    } else {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while (first != NULL &&  second != NULL) {
        if (first->value < second->value) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if (first != NULL) {
        last->next = first;
    }else if (second != NULL) {
        last->next = second;
    }
    
    return third;
}

bool isLoop(Node *first) {
    Node *p = first;
    Node *q = first;
    
    do {
        p = p->next;
        q = q->next;
        q = (q != NULL)?q->next:NULL;
    } while (p!=NULL && q!=NULL && p!=q);
    
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p == q) {
        return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    Node *A = NULL;

    A = insertNew(A, 1, 2);
    A = insertNew(A, 2, 4);
    A = insertNew(A, 3, 6);
    A = insertNew(A, 4, 8);

    Node *B = NULL;

    B = insertNew(B, 1, 3);
    B = insertNew(B, 2, 5);
    B = insertNew(B, 3, 7);
    
    Node *D = mergeList(A, B);
    display(D);
    
    Node *t1 = A->next->next->next;
    Node *t2 = A->next->next->next->next->next->next;
    t2->next = t1;
    
    if (isLoop(t1)) {
        cout << "Loop in t2 exists" << endl;
    } else {
        cout << "Loop in t2 does not exists" << endl;
    }

    return 0;
}
