//! This code gives the self made weighted graph ADT with
//! basic implementational functions for creating a
//! adjacency matrix for the graph.
//! Code can be used for both undirected and directed weighted graphs.
//! Remember that edge weights should be non negative only.

#include <iostream>
using namespace std;

/// class to control the graph in form
/// of a matrix.
/// It is simpler as compared to the formulation
/// of adjacency list of a graph.
class graph_matrix
{
    private:
    int** mat;
    int size;

    public:
    graph_matrix(int n);
    int length();
    int* get(int i);
    void insert_double(int a,int b,int w);
    void insert_single(int a,int b,int w);
    void display();
    void clear();
};

/// Constructor to make the initial graph with
/// no edges.
/// O(N^2) time where N is the total number of vertices.
graph_matrix::graph_matrix(int n)
{
    size=n;
    mat=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        mat[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++) mat[i][j]=-1;
    }
    return;
}

/// Returns the size of graph.
/// O(1) time.
int graph_matrix::length()
{
    return size;
}

/// Returns the HEAD for the linked list
/// containing vertices directly connected to the
/// vertex with index i.
/// O(1) time.
int* graph_matrix::get(int i)
{
    if(i>=size) return NULL;
    else return mat[i];
}

/// insert function for a undirected graph creation.
/// O(1) time.
void graph_matrix::insert_double(int a,int b,int w)
{
    if(a>=size || b>=size || a==b) return;
    mat[a][b]=w;    mat[b][a]=w;
    return;
}

/// insert function for a directed graph edge.
/// O(1) time.
void graph_matrix::insert_single(int a,int b,int w)
{
    if(a>=size || b>=size || a==b) return;
    mat[a][b]=w;
    return;
}

/// display function which displays the joined vertices
/// with the type of joint.
/// O(|V|^2) time.
void graph_matrix::display()
{
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(mat[i][j]==-1) continue;
            else if(mat[j][i]==-1) cout<<i<<"  -> "<<j<<"\n";
            else if(i<j) cout<<i<<" <-> "<<j<<"\n";
        }
    }
    return;
}

/// clears all the edges of the graph.
/// O(|V|^2) time.
void graph_matrix::clear()
{
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            mat[i][j]=-1;
        }
    }
    return;
}
