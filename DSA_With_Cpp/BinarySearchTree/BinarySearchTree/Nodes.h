//
//  Nodes.h
//  BinarySearchTree
//
//  Created by Niladri Ray Choudhury on 30/06/24.
//

#ifndef Nodes_h
#define Nodes_h

class TreeNode {
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    TreeNode(int value): left(nullptr), data(value), right(nullptr) {}
};

class Node {
    
public:
    Node *next;
    TreeNode *address;
    
    Node(TreeNode *add): next(nullptr), address(add) {}
    Node() {
        next = nullptr;
        address = nullptr;
    }
};

#endif /* Nodes_h */
