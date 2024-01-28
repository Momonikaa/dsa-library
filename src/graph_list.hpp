//! This code gives the self made weighted graph ADT with
//! basic implementational functions for creating a
//! adjacency list for the graph.
//! Code can be used for both undirected and directed graphs with weights on the edges.
//! Remember that edge weights should be non negative only.

#include <iostream>
using namespace std;

/// This structure represents a single vertex in the graph.
/// The fields `next` and `prev` are not related to
/// the edges but rather correspond to the linked list in
/// the adjacency list representation.
struct vertex
{
    int num;      // Shows the index number of the vertex in the graph
    int weight;   // Shows the weight of that corresponding edge
    struct vertex* next;
    struct vertex* prev;
};

/// Class for controlling the adjacency list
/// structure of the graph.
class graph_list
{
    private:
    struct vertex** head;
    struct vertex** tail;
    struct vertex** SENT;
    int size;

    public:
    graph_list(int x);
    int length();
    vertex* get(int i);
    vertex* sent(int i);
    void insert_double(int a,int b,int w);
    void insert_single(int a,int b,int w);
    void display();
    void clear();
};

/// Making of a new vertex with required index number.
/// O(1) time.
vertex* make_vertex(int num,int weight)
{
    vertex *temp=new vertex;
    if(temp!=NULL) temp->num=num;
    temp->weight=weight;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

/// Inserting the vertex with required index value in a list's tail.
/// O(1) time.
vertex* insert_vertex(int num,int weight,vertex* TAIL,vertex* S)
{
    vertex *temp=make_vertex(num,weight);
    if(temp==NULL) {
        cerr<<"Memory full";
        return TAIL;
    }
    temp->next=S;       temp->prev=TAIL;
    if(TAIL!=NULL) TAIL->next=temp;    
    S->prev=temp;       TAIL=temp;
    return TAIL;
}

/// Releasing the memory used by the Doubly Linked List
/// representing edges connected to a single vertex.
/// O(N) time where N is the number of edges connected to this vertex.
void free_all(vertex *HEAD,vertex *TAIL,vertex* S)
{
    vertex *temp=HEAD;
    while(temp!=S) {
        if(temp->prev!=S) free(temp->prev);
        temp=temp->next;
    }
    free(TAIL);
    return;
}

/// Priting the contents of a Doubly Linked List
/// showing the edges for a vertex.
/// O(N) time where N is the number of edges connected to this vertex.
void print_all(vertex* HEAD,vertex* S)
{
    vertex* temp=HEAD;
    while(temp!=S) {
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    return; 
}

/// Contructor for making a graph with x number of vertices.
/// O(x) time.
graph_list::graph_list(int x)
{
    size=x;
    SENT=(vertex**)malloc(x*sizeof(vertex*));
    head=(vertex**)malloc(x*sizeof(vertex*));
    tail=(vertex**)malloc(x*sizeof(vertex*));
    for(int i=0;i<x;i++) {
        SENT[i]=new vertex;
        SENT[i]->num=-1;
        SENT[i]->weight=-1;
        SENT[i]->next=SENT[i];
        SENT[i]->prev=SENT[i];
        head[i]=SENT[i];
        tail[i]=SENT[i];
    }
    return;
}

/// Returns the size of graph.
/// O(1) time.
int graph_list::length()
{
    return size;
}

/// Returns the HEAD for the linked list
/// containing vertices directly connected to the
/// vertex with index i.
/// O(1) time.
vertex* graph_list::get(int i)
{
    if(i>=size) return NULL;
    else return head[i];
}

/// Returns the SENTINEL vertex for the linked list
/// containing vertices directly connected to the
/// vertex with index i.
/// O(1) time.
vertex* graph_list::sent(int i)
{
    if(i>=size) return NULL;
    else return SENT[i];
}

/// insert an edge joining the a th 
/// and b th vertices in the graph like a <-> b.
/// O(1) time.  
void graph_list::insert_double(int a,int b,int w)
{
    if(a>=size || b>=size) return;

    tail[a]=insert_vertex(b,w,tail[a],SENT[a]);
    if(head[a]==SENT[a]) {
        head[a]=tail[a];    SENT[a]->next=head[a];
        head[a]->prev=SENT[a];
    }
    
    tail[b]=insert_vertex(a,w,tail[b],SENT[b]);
    if(head[b]==SENT[b]) {
        head[b]=tail[b];    SENT[b]->next=head[b];
        head[b]->prev=SENT[b];
    }
    
    return;
}

/// insert an edge joining the a th 
/// and b th vertices in the graph only in direction a -> b.
/// O(1) time.  
void graph_list::insert_single(int a,int b,int w)
{
    if(a>=size || b>=size) return;
    
    tail[a]=insert_vertex(b,w,tail[a],SENT[a]);
    if(head[a]==SENT[a]) {
        head[a]=tail[a];    SENT[a]->next=head[a];
        head[a]->prev=SENT[a];
    }
    
    return;
}

/// display() the adjacency list representation
/// of the graph explicitly.
/// O(|V|+2*|E|) time where |V| is number of vertices and |E| is number of edges.
void graph_list::display()
{
    for(int i=0;i<size;i++) {
        cout<<i<<"->";
        print_all(head[i],SENT[i]);
    }
    return;
}

/// clear() all the data present in the graph.
/// O(|V|+2*|E|) time where |V| is number of vertices and |E| is number of edges.
void graph_list::clear()
{
    for(int i=0;i<size;i++) {
        free_all(head[i],tail[i],SENT[i]);
        SENT[i]->next=SENT[i];
        SENT[i]->prev=SENT[i];
        head[i]=SENT[i];
        tail[i]=SENT[i];
    }
    return;
}
