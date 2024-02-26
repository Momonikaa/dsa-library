//! This is a Binary Tree structure controlling ADT with some member functions to control the workflow.
//! This can take various numbers from the user and form a binary tree from it.
//! Formation of the tree can be done in either balanced way or
//! left biased or right biased.

#include "vector.hpp"
#include "stack.hpp"

template<class T>
struct treenode {
    struct treenode* parent;
    struct treenode* left;
    struct treenode* right;
    T data;
};

template<class T>
class tree {
    private:
    treenode<T>* root;
    treenode<T>* s;
    int h;

    public:
    tree();
    void insert_balanced(T x);
    void insert_left(T x);
    void insert_right(T x);
    vector<T> inorder();
    vector<T> preorder();
    vector<T> postorder();
    treenode<T>* get(T p);
    int ndepth(treenode<T>* node);
    int nheight(treenode<T>* node);
    int height();
    T ndata(treenode<T>* node);
    treenode<T>* parent(treenode<T>* node);
    treenode<T>* lchild(treenode<T>* node);
    treenode<T>* rchild(treenode<T>* node);
};

template<class T>
tree<T>::tree() {
    h=0;
    s=new treenode<T>;
    root=s;
    s->left=s;  s->right=s;
    s->parent=s;
}

template<class T>
T tree<T>::ndata(treenode<T>* node) {
    return node->data;
}

template<class T>
treenode<T>* tree<T>::parent(treenode<T>* node)
{
    return node->parent;
}

template<class T>
treenode<T>* tree<T>::lchild(treenode<T>* node) {
    return node->left;
}

template<class T>
treenode<T>* tree<T>::rchild(treenode<T>* node) {
    return node->right;
}

template<class T>
int tree<T>::height() {
    return h;
}

template<class T>
void tree<T>::insert_balanced(T val) {
    treenode<T>* temp=new treenode<T>;
    temp->data=val;
    treenode<T>* x=root;
    for(int i=0;i<h;i++) {
        if(x->right==NULL) x=x->left;
        else x=x->right;
    }
    return;
}

template<class T>
void tree<T>::insert_left(T x) {

}

template<class T>
void tree<T>::insert_right(T x) {

}

template<class T>
vector<T> tree<T>::preorder() {

}

template<class T>
vector<T> tree<T>::inorder() {

}

template<class T>
vector<T> tree<T>::postorder() {

}

template<class T>
treenode<T>* tree<T>::get(T p) {

}

template<class T>
int tree<T>::ndepth(treenode<T>* node) {

}

template<class T>
int tree<T>::nheight(treenode<T>* node) {

}
