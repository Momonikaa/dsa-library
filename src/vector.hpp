//! Header File to control the implementation of Vector Data Structure

template<class T>
class vector {
    public:
    T* arr;
    int len,b;
    
    vector();
    vector(int p);
    vector(int p,T val);
    vector(T a[],int n);
    void push_back(T x);
    T pop_back();
    int size();
    bool isEmpty();
    void sort();
    void des_sort();
    T get(int i);
    void swap(int a,int b);
    void set(int i,T x);
    void resize(int new_size);
};

/// O(1) default contructor.
template<class T>
vector<T>::vector() {
    b=-1;   len=1;
    arr=(T*)malloc(sizeof(T));
    return;
}

/// O(1) parameterized constructor.
template<class T>
vector<T>::vector(int p) {
    b=p-1;  len=p;
    arr=(T*)malloc(len*sizeof(T));
    return;
}

/// O(N) parameterized constructor with initial values.
template<class T>
vector<T>::vector(int p,T val) {
    len=p; arr=(T*)malloc(len*sizeof(T));
    for(int i=0;i<p;i++) arr[i]=val;
    b=p-1;
    return;
}

/// Resize functioning of the vector.
template<class T>
void vector<T>::resize(int new_size) {
    
    return;
}

/// Takes a array and represent it as vector for using vector specific
/// functions implemeted in the class `vector` for self-made vector ADT.
/// An object of `vector` class is returned and the code is non-destructive.
/// O(N) runtime complexity algorithm.
template<class T>
vector<T>::vector(T a[],int n) {
    len=n; arr=(T*)malloc(len*sizeof(T));
    for(int i=0;i<n;i++) arr[i]=a[i];
    b=n-1;
    return;
}

/// Push the value at the back of the array.
/// If required the size of vector is increased.
/// O(1) time in general.
template<class T>
void vector<T>::push_back(T x) {
    if(b<(len-1)) { b++; arr[b]=x; }
    else {
        arr=(T*)realloc(arr,2*len*sizeof(T));
        b++;  arr[b]=x; len=2*len;
    }
    return;
}

/// Returns the boolean value for "Is the vector empty?".
/// O(1) algorithm runtime.
template<class T>
bool vector<T>::isEmpty() {
    if(b==-1) return true;
    else return false;
}

/// Returns the respective element, and if it overshoots the size than the last element.
/// O(1) algorithm runtime.
template<class T>
T vector<T>::get(int i) {
    if(i>b) return arr[b];
    return arr[i];
}

/// Removes and Returns the last element in the vector.
/// O(1) time in general.
template<class T>
T vector<T>::pop_back() {
    if(b>-1) {
        T p=arr[b]; b--;
        if(b<(len/2)) {
            arr=(T*)realloc(arr,(len/2)*sizeof(T));
            len=(len/2);
        }
        return p;
    }    
    else return -1;
}

/// Returns the size of the vector.
/// O(1) runtime complexity algorithm.
template<class T>
int vector<T>::size() {
    return (b+1);
}

template<class T>
/// Sorts the vector in ascending order.
/// O(NlogN) runtime efficient sorting algorithm
void vector<T>::sort() {
    if(size()!=1) {
        vector<T> x,y;
        for(int i=0;i<size();i++) {
            if(i<(size()/2)) x.push_back(arr[i]);
            else y.push_back(arr[i]);
        }
        x.sort(); y.sort();
        int p=0,q=0;
        for(int i=0;i<len;i++) {
            if(p==(size()/2)) { arr[i]=y.get(q); q++; }
            else if(q==(size()-(size()/2))) { arr[i]=x.get(p); p++; }
            else if(x.get(p)<=y.get(q)) { arr[i]=x.get(p); p++; }
            else { arr[i]=y.get(q); q++; }
        }
    }
    return;
}

/// Sorts the vector in descending order.
/// O(NlogN) runtime efficient sorting algorithm.
template<class T>
void vector<T>::des_sort() {
    if(size()!=1) {
        vector<T> x,y;
        for(int i=0;i<size();i++) {
            if(i<(size()/2)) x.push_back(arr[i]);
            else y.push_back(arr[i]);
        }
        x.des_sort(); y.des_sort();
        int p=0,q=0;
        for(int i=0;i<len;i++) {
            if(p==(size()/2)) { arr[i]=y.get(q); q++; }
            else if(q==(size()-(size()/2))) { arr[i]=x.get(p); p++; }
            else if(x.get(p)>=y.get(q)) { arr[i]=x.get(p); p++; }
            else { arr[i]=y.get(q); q++; }
        }
    }
    return;
}

/// Swapping of specified elements in the vector.
/// O(1) algorithm runtime.
template<class T>
void vector<T>::swap(int a,int b) {
    if(a>=size() || b>=size()) return;
    else { T t=arr[a]; arr[a]=arr[b];  arr[b]=t; }
    return;
}

/// Set the element at a specified index to a specified value.
/// It wont work if the index specified is greater than the size.
/// O(1) algorithm runtime.
template<class T>
void vector<T>::set(int i,T x) {
    if(i>b) return;
    arr[i]=x;
    return;
}

/// This is a very efficient sorting algorithm called as Merge Sort.
/// It is easy to implement which partitions the array into two then solve both
/// and then add them into the first array at appropriate positions.
/// It is also used in the sorting for vectors.
/// O(NlogN) is the worst time complexity of this algorithm.
template<typename T>
void merge_sort(T* a,int n) {
    if(n!=1) {
        T x[n/2],y[n-(n/2)];
        for(int i=0;i<n;i++) {
            if(i<(n/2)) x[i]=a[i];
            else y[i-(n/2)]=a[i];
        }
        merge_sort(x,(n/2)); merge_sort(y,n-(n/2));
        int p=0,q=0;
        for(int i=0;i<n;i++) {
            if(p==(n/2)) { a[i]=y[q]; q++; }
            else if(q==(n-(n/2))) { a[i]=x[p]; p++; }
            else if(x[p]<=y[q]) { a[i]=x[p]; p++; }
            else { a[i]=y[q]; q++; }
        }
    }
    return;
}
