//! Priority Queues are one of the applications
//! of the heap data structure which is inturn managed through
//! the vector data structure.
//! This is a self made priority queue ADT which has basic push(),pop() like queue
//! But the pop() would be done according to priorities assigned to the particular values.

#include "heap.hpp"
using namespace std;

class pyq {
    private:
    char* dat;
    heap prior;
    int size;

    public:
    pyq();
    pyq(int x);

};

pyq::pyq()
{
    
}
