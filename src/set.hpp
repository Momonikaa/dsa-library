//! Sets can be created in various ways all of which are held in this same file.
//! This contains the bitvector and sorted and unsorted list representations.

#include <iostream>
using namespace std;

/// Structure for linked list implementation
/// of the sets.
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

/// Class to control bitvector version
/// of the set.
class set_bitvector
{
    private:
    bool* arr;
    int max;
    int min;
    int len;

    public:
    set_bitvector();
    set_bitvector(int a,int b);
    void add(int x);
    bool check(int x);
    void remove(int x);
    int size();
    int* range();
};

/// Class to control sorted linked list version
/// of the set.
class set_slist
{
    private:
    struct node* HEAD;
    struct node* TAIL;
    struct node* S;

    public:
    set_slist();
    
};

/// Class to control unsorted linked list version
/// of the set.
class set_ulist
{
    private:
    struct node* HEAD;
    struct node* TAIL;
    struct node* S;
};

/// Default constructor for the bitvector set
/// O(1) time as max and min are decided already.
set_bitvector::set_bitvector()
{
    max=100;
    min=-100;
    len=200;
    arr=(bool*)malloc(len*sizeof(bool));
    for(int i=0;i<len;i++) arr[i]=false;
    return;
}

/// Parameterized constructor for the bitvector set
/// O(m2-m1) time.
set_bitvector::set_bitvector(int m1,int m2)
{
    max=m2;
    min=m1;
    len=(max-min+1);
    arr=(bool*)malloc(len*sizeof(bool));
    for(int i=0;i<len;i++) arr[i]=false;
    return;
}

/// Add element into the set.
/// Duplicate elements don't matter in sets.
/// O(1) time.
void set_bitvector::add(int x)
{
    int i=x-min;
    if(i<0 || i>=len) return;
    arr[i]=true;
    return;
}

