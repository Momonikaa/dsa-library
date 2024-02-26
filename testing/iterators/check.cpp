#include <iostream>

// Node class representing a single node in the linked list
template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

// Iterator class for the linked list
template<typename T>
class LinkedListIterator {
private:
    Node<T>* current; // Pointer to the current node

public:
    // Constructor
    LinkedListIterator(Node<T>* node) : current(node) {}

    // Overloaded operators
    T& operator*() const {
        return current->data; // Dereference operator returns the data of the current node
    }

    LinkedListIterator& operator++() {
        current = current->next; // Increment operator moves to the next node
        return *this;
    }

    bool operator!=(const LinkedListIterator& other) const {
        return current != other.current; // Comparison operator checks if iterators are not equal
    }
};

// Custom singly linked list class
template<typename T>
class LinkedList {
private:
    Node<T>* head; // Pointer to the head of the list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to add an element to the front of the list
    void push_front(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to obtain an iterator pointing to the beginning of the list
    LinkedListIterator<T> begin() const {
        return LinkedListIterator<T>(head);
    }

    // Function to obtain an iterator pointing to the end of the list
    LinkedListIterator<T> end() const {
        return LinkedListIterator<T>(nullptr);
    }
};

// Overload begin and end functions to enable range-based iteration
template<typename T>
auto begin(const LinkedList<T>& list) {
    return list.begin();
}

template<typename T>
auto end(const LinkedList<T>& list) {
    return list.end();
}

int main() {
    // Create a custom linked list and add some elements
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    // Iterate through the list using range-based for loop
    for (auto element : list) {
        std::cout << element << " ";
    }

    return 0;
}
