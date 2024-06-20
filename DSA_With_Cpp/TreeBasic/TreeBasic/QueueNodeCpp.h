//
//  QueueNodeCpp.h
//  TreeBasic
//
//  Created by Niladri Choudhury on 20/06/24.
//

#ifndef QueueNodeCpp_h
#define QueueNodeCpp_h
#include "TreeNodeCpp.h"

class QueueNode {
public:
    TreeNode *data;
    QueueNode *next;
    
    QueueNode(TreeNode * treeNodeAddress): data(treeNodeAddress), next(nullptr) {}
};

#endif /* QueueNodeCpp_h */
