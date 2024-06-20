//
//  TreeNodeCpp.h
//  TreeBasic
//
//  Created by Niladri Choudhury on 20/06/24.
//

#ifndef TreeNodeCpp_h
#define TreeNodeCpp_h

class TreeNode {
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    
    TreeNode(int value): left(nullptr), data(value), right(nullptr) {}
};
#endif /* TreeNodeCpp_h */
