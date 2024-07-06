//
//  Nodes.h
//  AVLTree
//
//  Created by Niladri Ray Choudhury on 03/07/24.
//

#ifndef Nodes_h
#define Nodes_h

class TreeNode {
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    int height; // Should indicate the maximum_height(left sub-tree, right sub-tree).
    
    TreeNode(int value) {
        this->data = value;
        left = right = nullptr;
        height = 1;
    }
};

#endif /* Nodes_h */
