//! Self Made Queue ADT with push() pop() and display()
//! Implemented using a doubly linked list and a sentinel node.
//! All operations are O(1) except display() which is O(N)
//! The program is implemented in template classes so it uses the fact that the type of data in queue class object
//! has a proper ordering that is the data type supports >, < and = operations.

template<class T>
struct queuenode {
    struct queuenode* prev;
    T data;
    struct queuenode* next;
};

template<class T>
class queue {
    private:
    struct queuenode<T>* start;
    struct queuenode<T>* end;
    struct queuenode<T>* s;
    public:
    queue();
    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    T front();
    T back();
};

/// Constructor for the Queue ADT
/// O(1) time complexity runtime
template<class T>
queue<T>::queue() {
    s=new queuenode<T>;
    s->prev=s; s->next=s;
    start=s; end=s;
    return;
}

/// Returns 1 for empty queue otherwise 0.
/// O(1) runtime complexity
template<class T>
bool queue<T>::isEmpty() {
    if(start==s) return true;
    else return false;
}

/// Adds a particular value at the end of the queue.
/// O(1) time
template<class T>
void queue<T>::enqueue(T x) {
    queuenode<T>* temp=new queuenode<T>;
    temp->data=x; temp->next=s;
    s->prev=temp; temp->prev=end;
    end->next=temp; end=temp;
    if(start==s) start=end;
    return;
}

/// Deletes a element from the beginning and also returns the element deleted.
/// O(1) time complexity
/// Remember that for this the queue should not be empty
template<class T>
T queue<T>::dequeue() {
    T p=start->data;
    start=start->next; free(start->prev);
    start->prev=s; s->next=start;
    return p;
}

/// Returns the front element of the queue.
/// O(1) time
/// Remember that for this the queue should not be empty
template<class T>
T queue<T>::front() {
    return start->data;
}

/// Returns the back element of the queue.
/// O(1) time
/// Remember that for this the queue should not be empty
template<class T>
T queue<T>::back() {
    return end->data;
}
