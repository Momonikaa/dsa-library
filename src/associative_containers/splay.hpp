//! Implementation of the concept of Splay Trees.
//! They provide an O(logN) amortized time complexity
//! on dictionary operations.

////////////////////////////////// Libraries //////////////////////////////////////////////////////////////////////////
// FORM A DETAILED ANALYSIS SPLAY TREES
// COMPLETE THE FUNCTIONS FOR DELETION SO MAYBE NEXT DAY
#include<iostream>
using namespace std;

/////////////////////////////////// Helper Functions //////////////////////////////////////////////////////////////////
/// Helper function useful for sorting a given array.
/// It takes worst case O(N*logN) time.
void merge_sort(int* arr,int n)
{
    if(n==1) return;
    else {
        int* arr1=(int*)malloc((n/2)*sizeof(int));
        int* arr2=(int*)malloc((n-n/2)*(sizeof(int)));
        for(int i=0;i<n;i++) {
            if(i<n/2) arr1[i]=arr[i];
            else arr2[i-n/2]=arr[i];
        }
        merge_sort(arr1,n/2);
        merge_sort(arr2,n-n/2);
        int i=0,j=0;
        while(i<n/2 || j<n-n/2) {
            if(i==n/2) { arr[i+j]=arr2[j]; j++; }
            else if(j==n-n/2) { arr[i+j]=arr1[i]; i++; }
            else if(arr1[i]>=arr2[j]) { arr[i+j]=arr2[j]; j++; }
            else { arr[i+j]=arr1[i]; i++; }
        }
        return;
    }
}

///////////////////////////////////// Binary Search Tree Node /////////////////////////////////////////////////////////
/// Structure to represent a node in a Binary Search Tree
struct bstnode {
    int num;
    struct bstnode* parent;
    struct bstnode* left;
    struct bstnode* right;
};

/// Helper function to deal with the requests of creating nodes
/// all functions work in O(1) time and provide the pointer
/// to an instance of the BST node created with required
/// specifications.

/// Create Null Node
struct bstnode* create()
{
    struct bstnode* temp=new bstnode;
    temp->num=0;
    temp->parent=temp->left=temp->right=NULL;
    return temp;
}

/// Create Value Assigned Node
struct bstnode* create(int num)
{
    struct bstnode* temp=new bstnode;
    temp->num=num;   temp->parent=NULL;
    temp->left=temp->right=NULL;
    return temp;
}

/// Create Parent Node
struct bstnode* create(struct bstnode* left,struct bstnode* right)
{
    struct bstnode* temp=new bstnode;
    temp->num=0;   temp->parent=NULL;
    temp->left=left; temp->right=right;
    return temp;
}

/// Create Full Detail Node
struct bstnode* create(int num,struct bstnode* parent,struct bstnode* left,struct bstnode* right)
{
    struct bstnode* temp=new bstnode;
    temp->num=num; temp->parent=parent;
    temp->left=left; temp->right=right;
    return temp;
}

/// Recursive BST Assigner
/// This code takes a sorted array and converts it into a BST
/// in O(N*logN) time.
struct bstnode* create_bst(int* arr,int start,int end)
{
    if(start>end) return NULL;
    else if(start==end) return create(arr[0]);
    else {
        int mid=(start+end)/2;
        struct bstnode* root=create(arr[mid]);
        root->left=create_bst(arr,start,mid-1);
        root->right=create_bst(arr,mid+1,end);
        if(root->left!=NULL) root->left->parent=root;
        if(root->right!=NULL) root->right->parent=root;
        return root;
    }
}

////////////////////////////////////// Splay Tree Class Structure /////////////////////////////////////////////////////
/// Class to control and encapsulate an instance of Splay Tree for Dictionary Operations
/// This provides functions necessary to implement dictionary operations to
/// the outside world.
class Splay {
    private:
    struct bstnode* root;
    int size;
    void zig(struct bstnode* point);
    void zag(struct bstnode* point);

    public:
    Splay(int* arr,int n);
    Splay();
    void insert(int x);
    int remove(int x);
    bool search(int x);
};

/// Code for creation of Empty Splay Tree
/// O(1) time
Splay::Splay()
{
    root=NULL; size=0;
    return;
}

/// Code to create a BST such that all the values of the
/// array are present inserted into it.
/// Direct insertion may take -> O(N^2) time.
/// Sorting and insertion from the middle of the array ensures O(N*logN) time.
/// this feature could be exploited as the values to be added are known in advance.
Splay::Splay(int* arr,int n)
{
    merge_sort(arr,n);
    size=n; root=create_bst(arr,n);
    return;
}

/// Code for Rotation in a Binary Search Tree.
/// Zig Rotation corresponds to Clockwise Rotation.
/// O(1) time
void Splay::zig(struct bstnode* point)
{
    if(point==NULL || point->left==NULL) return;
    if(point->parent!=NULL) {
        if(point->parent->left==point) point->parent->left=point->left;
        else point->parent->right=point->left;
    }
    else root=point->left;
    point->left->parent=point->parent;
    point->parent=point->left;
    point->left->right=point;
    point->left=point->left->right;
    if(point->left!=NULL) point->left->parent=point;
    return;
}

/// Code for Rotation in a Binary Search Tree.
/// Zag Rotation corresponds to Anti-Clockwise Rotation.
/// O(1) time
void Splay::zag(struct bstnode* point)
{
    if(point==NULL || point->right==NULL) return;
    if(point->parent!=NULL) {
        if(point->parent->left==point) point->parent->left=point->right;
        else point->parent->right=point->right;
    }
    else root=point->right;
    point->right->parent=point->parent;
    point->parent=point->right;
    point->right->left=point;
    point->right=point->right->left;
    if(point->right!=NULL) point->right->parent=point;
    return;
}

/////////////////////////////////// Splay Tree Dictionary Operations //////////////////////////////////////////////////
/// Code for Insertion in a BST
/// This can take a worst case of O(N) time also but
/// will take amortized O(logN) time if searching is also
/// repeatedly used on the BST.
void Splay::insert(int x)
{
    struct bstnode* temp=create(x);
    struct bstnode *iter=NULL,*next=root;
    int flag=-1;
    while(next!=NULL) {
        iter=next;
        if(next->val>=x) { next=next->left; flag=0; }
        else { next=next->right; flag=1; }
    }
    if(iter==NULL) root=iter;
    else if(flag==0) iter->left=temp;
    else iter->right=temp;
    return;
}

/// A recursive algorithm for making a
/// node traverse from its initial position
/// to the topmost position just below the root.
void recurse_to_top(struct bstnode* point)
{
    if(point->parent==NULL || point->parent==root) return;
    else {
        if(point==point->parent->left) zig(point->parent);
        else zag(point->parent);
    }
}

/// Code for Searching in a BST
bool Splay::search(int x)
{
    struct bstnode* temp=root;
    while(temp!=NULL) {
        if(temp->num==x) {
            while(temp->parent!=NULL && temp->parent!=root) {
                if(temp==temp->parent->left) zig(temp->parent);
                else zag(temp->parent);
            }
            return true;
        }
        else if(temp->num>x) temp=temp->left;
        else temp=temp->right;
    }
    return false;
}

/// Code for Deletion in a BST
int Splay::remove(int x)
{

}
