#include <iostream>
#include "../../templates/header_files/stack.hpp"
#include "../../templates/header_files/vector.hpp"
using namespace std;

int main() {
    int n;  cin>>n;
    stack<vector<int>> st;
    for(int i=0;i<n;i++) {
        vector<int> t(n);
        for(int i=0;i<n;i++) { int p; cin>>p; t.set(i,p); }
        st.push(t);
    }
    for(int i=0;i<n;i++) cout<<st.pop().get(0)<<"\n";
    return 0;
}
