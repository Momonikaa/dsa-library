//! Self Made Stack ADT with push() pop() and display()
//! Implemented using a doubly linked list and a sentinel node.
//! All operations are O(1) except display() which is O(N)
//! The program is implemented in template classes so it uses the fact that the type of data in stack class object
//! has a proper ordering that is the data type supports >, < and = operations.

template<class T>
struct stacknode {
    struct stacknode* prev;
    T data;
    struct stacknode* next;
};

template<class T>
class stack {
    private:
    struct stacknode<T>* last;
    struct stacknode<T>* s;
    public:
    stack();
    void push(T x);
    T pop();
    bool isEmpty();
    T top();
};

/// Constructor for the Stack ADT
/// O(1) time complexity runtime
template<class T>
stack<T>::stack() {
    s=new stacknode<T>;
    s->prev=s;
    s->next=s; last=s;
    return;
}

/// Returns 1 for empty stack otherwise 0.
/// O(1) runtime complexity
template<class T>
bool stack<T>::isEmpty() {
    if(last==s) return true;
    else return false;
}

/// Adds a particular value at the top of the stack.
/// O(1) time
template<class T>
void stack<T>::push(T x) {
    stacknode<T>* temp=new stacknode<T>;
    temp->data=x; temp->next=s;
    s->prev=temp; temp->prev=last;
    last->next=temp; last=temp;
    return;
}

/// Deletes a element from the top and also returns the element deleted.
/// O(1) time complexity
/// Remember that for this the stack should not be empty
template<class T>
T stack<T>::pop() {
    T p=last->data;
    last=last->prev; free(last->next);
    return p;
}

/// Returns the top element of the stack.
/// O(1) time
/// Remember that for this the stack should not be empty
template<class T>
T stack<T>::top() {
    return last->data;
}
