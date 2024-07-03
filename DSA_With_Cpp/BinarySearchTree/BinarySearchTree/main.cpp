//
//  main.cpp
//  BinarySearchTree
//
//  Created by Niladri Ray Choudhury on 28/06/24.
//

#include <iostream>
#include <array>
#include "Nodes.h"
#include "stack.h"

using namespace std;

class BST {
    
public:
    TreeNode *root;
    
    BST(): root(nullptr) {}
    
    void Iinsert(int key) {
        TreeNode *t = new TreeNode(key);
        TreeNode *p = root;
        TreeNode *r = nullptr;
        if (root == nullptr) {
            root = t;
            return;
        }
        while (p != nullptr) {
            r = p;
            if (p->data == key) {
                cout << "Value already present in tree..." << endl;
                return;
            }
            if (p->data > key) {
                p = p->left;
            } else if (p->data < key) {
                p = p->right;
            }
        }
        if (r->data > key) {
            r->left = t;
        } else if (r->data < key) {
            r->right = t;
        }
    }
    
    TreeNode * Rinsert(TreeNode *t, int key) {
        if (t == nullptr) {
            TreeNode *p = new TreeNode(key);
            return p;
        }
        
        if (t->data > key) {
            t->left = Rinsert(t->left, key);
        } else if (t->data < key) {
            t->right = Rinsert(t->right, key);
        }
        
        return t;
    }
    
    TreeNode * Isearch(TreeNode *p, int key) {
        while (p != nullptr) {
            if (p->data == key) {
                return p;
            }
            if (p->data < key) {
                p = p->right;
            } else {
                p = p->left;
            }
        }
        return nullptr;
    }
    
    TreeNode * Rsearch(TreeNode *p, int key) {
        
        if (p->data == key) {
            return p;
        }
        if (p == nullptr) {
            return nullptr;
        }
        
        if (p->data < key) {
            return Rsearch(p->right, key);
        } else {
            return Rsearch(p->left, key);
        }
    }
    
    void inorderTraversal(TreeNode *p){
        if (p == nullptr) {
            return;
        }
        inorderTraversal(p->left);
        cout << p->data << ", ";
        inorderTraversal(p->right);
    }
    
    int height(TreeNode *p) {
        int x, y;
        
        if (p != nullptr) {
            x = height(p->left);
            y = height(p->right);
            if (x > y) {
                return x + 1;
            } else {
                return y + 1;
            }
        }
        return 0;
    }
    
    TreeNode * InPredecessor(TreeNode *p) {
        while (p != nullptr && p->right != nullptr) {
            p = p->right;
        }
        return p;
    }
    TreeNode * InSuccsessor(TreeNode *p) {
        while (p != nullptr && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }
    
    TreeNode * Rdelete(TreeNode *p, int key) {
        
        if (p == nullptr) {
            return nullptr;
        }
        
        if (p->left == nullptr && p->right == nullptr) {
            if (p == root) {
                root = nullptr;
            }
            
            delete p;
            return nullptr;
        }
        
        if (key > p->data) {
            p->right = Rdelete(p->right, key);
        } else if (key < p->data) {
            p->left = Rdelete(p->left, key);
        } else {
            TreeNode *temp = nullptr;
            if (height(p->left) > height(p->right)) {
                temp = InPredecessor(p->left);
                p->data = temp->data;
                p->left = Rdelete(p->left, temp->data);
            } else {
                temp = InSuccsessor(p->right);
                p->data = temp->data;
                p->right = Rdelete(p->right, temp->data);
            }
        }
        return p;
    }
    
    void createPre(int arr[], int size) {
        Stack stk;
        TreeNode *t;
        int i = 0;
        root = new TreeNode(arr[i++]);
        TreeNode *p = root;
        
        while (i < size) {
            if (arr[i] < p->data) {
                t = new TreeNode(arr[i++]);
                p->left = t;
                stk.push(p);
                p = t;
            } else {
                TreeNode *temp = stk.getTop();
                int a= (temp == nullptr) ? INT8_MAX : temp->data;
                if (arr[i] > p->data && arr[i] < a) {
                    t = new TreeNode(arr[i++]);
                    p->right = t;
                    p = t;
                } else {
                    p = stk.pop();
                }
            }
        }
        
        
    }

};

int main(int argc, const char * argv[]) {
    BST tree;
    
    tree.Iinsert(10);
    tree.Iinsert(5);
    tree.Iinsert(20);
    tree.Iinsert(8);
    tree.Iinsert(30);
    tree.Iinsert(20);
    tree.inorderTraversal(tree.root);
    return 0;
}
