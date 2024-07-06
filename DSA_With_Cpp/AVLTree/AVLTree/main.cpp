//
//  main.cpp
//  AVLTree
//
//  Created by Niladri Ray Choudhury on 03/07/24.
//

#include <iostream>
#include "Nodes.h"

using namespace std;

class AVLTree {
public:
    TreeNode *root;
    AVLTree(): root(nullptr) {}
    
    int getTreeHeight(TreeNode *p) {
        int hLeft, hRight;
        
        hLeft = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
        hRight = (p != nullptr && p->right != nullptr) ? p->right->height : 0;
        
        return (hLeft > hRight) ? hLeft+1 : hRight+1;
    }
    
    int getbalancedFactor(TreeNode *p) {
        int hL = 0, hR = 0;
        
        hL = (p != nullptr && p->left != nullptr) ? p->left->height : 0;
        hR = (p != nullptr && p->right != nullptr) ? p->right->height : 0;
        
        return hL - hR;
    }
    
    TreeNode * doLLRotation(TreeNode *p) {
        TreeNode *pl = p->left;
        TreeNode *plr = pl->right;
        
        pl->right = p;
        p->left = plr;
        
        p->height = getTreeHeight(p);
        pl->height = getTreeHeight(pl);
        
        if (root == p) {
            root = pl;
        }
        
        return pl;
    }
    
    TreeNode * doLRRotation(TreeNode *p) {
        TreeNode *pl = p->left;
        TreeNode *plr = pl->right;
        
        p->left = plr->left;
        pl->right = plr->right;
        plr->left = pl;
        plr->right = p;
        
        if (root == p)
            root = plr;
            
        //Recalculate height
        pl->height = getTreeHeight(pl);
        plr->height = getTreeHeight(plr);
        p->height = getTreeHeight(p);
        
        return plr;
    }
    
    TreeNode * doRLRotation(TreeNode *p) {
        TreeNode *pr = p->right, *prl = pr->left;
        
        p->right = prl->left;
        pr->left = prl->right;
        
        prl->left = p;
        prl->right = pr;
        
        p->height = getTreeHeight(p);
        pr->height = getTreeHeight(pr);
        prl->height = getTreeHeight(prl);
        
        if (p == root) {
            root = prl;
        }
        
        return prl;
    }
    
    TreeNode * doRRRotation(TreeNode *p) {
        TreeNode *pr = p->right;
        TreeNode *prr = pr->right;
        
        p->right = pr->left;
        pr->left = p;
        
        // Recalculate height
        p->height = getTreeHeight(p);
        pr->height = getTreeHeight(pr);
        
        if (root == p) {
            root = pr;
        }
        
        return pr;
    }
    
    TreeNode * rInsert(TreeNode *p, int value) {
        if (root == nullptr) {
            TreeNode *t = new TreeNode(value);
            root = t;
            return t;
        }
        if (p == nullptr) {
            TreeNode *t = new TreeNode(value);
            return t;
        }
        
        if (value > p->data) {
            p->right = rInsert(p->right, value);
        } else if (value < p->data) {
            p->left = rInsert(p->left, value);
        } else {
            cout << "Value already present in tree..." << endl;
            return nullptr;
        }
        p->height = getTreeHeight(p);
        
        int bf = getbalancedFactor(p);
        
        if (getbalancedFactor(p) == 2 && getbalancedFactor(p->left) == 1) {
            // Perform LL rotation
            return  doLLRotation(p);
        } else if (getbalancedFactor(p) == 2 && getbalancedFactor(p->left) == -1) {
            // Perform LR rotation
            return doLRRotation(p);
        } else if (getbalancedFactor(p) == -2 && getbalancedFactor(p->right) == -1) {
            // Perform RR rotation
            return doRRRotation(p);
        } else if (getbalancedFactor(p) == -2 && getbalancedFactor(p->right) == 1) {
            // Perform RL rotation
            return doRLRotation(p);
        }
        
        return p;
    }
    
    
    
    
};

int main(int argc, const char * argv[]) {
    AVLTree tree;
    
    tree.rInsert(tree.root, 10);
    tree.rInsert(tree.root, 20);
    tree.rInsert(tree.root, 30);
    tree.rInsert(tree.root, 25);
    tree.rInsert(tree.root, 28);
    tree.rInsert(tree.root, 27);
    tree.rInsert(tree.root, 5);
    return 0;
}
