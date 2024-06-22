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
private:
    void preorderTreaversal(TreeNode *p) {
        if (p) {
            cout << p->data << ", ";
            preorderTreaversal(p->left);
            preorderTreaversal(p->right);
        }
    }
    
    void inorderTraversal(TreeNode *p) {
        if (p) {
            inorderTraversal(p->left);
            cout << p->data << ", ";
            inorderTraversal(p->right);
        }
    }
    
    void postorderTraversal(TreeNode *p) {
        if (p) {
            postorderTraversal(p->left);
            postorderTraversal(p->right);
            cout << p->data << ", ";
        }
    }
    
    void levelorderTraversal(TreeNode *p) {
        Queue q;
        cout << p->data << ", ";
        q.enqueue(p);
        while (!q.isEmpty()) {
            p = q.dequeue();
            if (p->left != nullptr) {
                cout << p->left->data << ", ";
                q.enqueue(p->left);
            }
            if (p->right != nullptr) {
                cout << p->right->data << ", ";
                q.enqueue(p->right);
            }
        }
    }
    
public:
    Queue queue;
    TreeNode *root;
    
    Tree() {
        root = nullptr;
        
    }
    
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
    
    void traversal(string type, TreeNode *p) {
        cout << type << " traversal result: " << endl;
        if (type == "preorder") {
            preorderTreaversal(p);
            cout << endl;
        } else if (type == "inorder") {
            inorderTraversal(p);
            cout << endl;
        } else if (type == "postorder") {
            postorderTraversal(p);
            cout << endl;
        } else if (type == "levelorder") {
            levelorderTraversal(p);
            cout << endl;
        }
    }
    
    int height(TreeNode *p) {
        int x=0, y=0;
        if (p == nullptr) {
            return 0;
        }
        
        x = height(p->left);
        y = height(p->right);
        if (x > y) {
            return x+1;
        } else {
            return y+1;
        }
    }
};

int main(int argc, const char * argv[]) {
    Tree tree;
    tree.create();
    cout << "Tree height: " << tree.height(tree.root) << endl;
    tree.traversal("preorder", tree.root);
    tree.traversal("inorder", tree.root);
    tree.traversal("postorder", tree.root);
    tree.traversal("levelorder", tree.root);
    return 0;
}
