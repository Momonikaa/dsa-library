//! This code will control a self made red black tree ADT
//! This is a complicated code and thus made independent of any other
//! data structure present in these implementation.
//! The code is involved in insert() and delete() from a red black tree.
//! All runtime complexities are as shown in the respective member functions.

//! These are an example of self balancing trees and determine the solution of an important problem
//! based on the dictionary maintenance in a system.

#include<iostream>
using namespace std;

struct rbtnode {
    int data;
    int color;
    struct rbtnode* left;
    struct rbtnode* right;
};

// Here rbt stands for Red Black Trees.
class rbt {
    private:
    struct rbtnode* root;
    int bl_height;
    int size;

    public:
};


// The major features to be implemented and which are quite
// tough as well are - Insert(), Delete(), Union() and Split()
// The split and Union operations are the toughest to be done in O(logN) time.
// Other easy operations like predecessor(), successor(), search(), max() and min() are also to be implemented.
int32_t main()
{
    cout<<"This is a interactive program to control a red black tree";
    int n;  cin>>n;
    return 0;
}
