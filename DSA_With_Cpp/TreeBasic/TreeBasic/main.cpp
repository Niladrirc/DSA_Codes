//
//  main.cpp
//  TreeBasic
//
//  Created by Niladri Choudhury on 17/06/24.
//

#include <iostream>
#include <stdio.h>
#include "TreeNodeCpp.h"
#include "QueueNodeCpp.h"
#include "Queue.h"

using namespace std;


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
}
