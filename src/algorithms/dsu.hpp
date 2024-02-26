//! This is an efficient disjoint set union structure.
//! This can maintain many disjoint sets and maintain them. The sets could be joined
//! as wanted and this is specifically used in some graph algorithms.

#include "vector.hpp"
#define MAX_DSU_SIZE 1e5

template<class T>
class DSU {
    private:
    vector<T> dsu_parent;
    vector<T> dsu_size;

    public:
    DSU(int size);
    void make(T v);
    T find(T v);
    void merge(T a,T b);
};

template<class T>
DSU<T>::DSU(int size=MAX_DSU_SIZE) {
    dsu_parent.resize(size);
    dsu_size.resize(size);
    return;
}

void make(int v) {
    dsu_parent[v]=v; dsu_size[v]=1;
    return;
}

int find(int v) {
    if(v==dsu_parent[v]) return v;
    return dsu_parent[v]=find(dsu_parent[v]);
}

void merge(int a,int b) {
    a=find(a); b=find(b);
    if(a!=b) {
        if(dsu_size[a]<dsu_size[b]) swap(a, b);
        dsu_parent[b]=a;
        dsu_size[a]+=dsu_size[b];
    }
    return;
}