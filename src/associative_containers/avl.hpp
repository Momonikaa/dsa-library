//! This code will control a self made AVL(Adelson Volsky Landis) tree ADT
//! This is a complicated code and thus made independent of any other
//! data structure present in these implementation.
//! The code is involved in insert() and delete() from an AVL tree.
//! All runtime complexities are as shown in the respective member functions.

//! These are an example of self balancing trees and determine the solution of an important problem
//! based on the dictionary maintenance in a system.

#include<bits/stdc++.h>
using namespace std;

struct avlnode {
    int data;
    int color;
    struct avlnode* left;
    struct avlnode* right;
};

// Here avl stands for AVL Trees. The tree is defined using a root
// and the size of the tree and number of black nodes in the path from root to
// any leaf node.
struct avl {
    struct avlnode* root;
    int bl_height;
    int size;
};

int32_t main()
{

}
