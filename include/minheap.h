#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
template<typename T>
class MinHeap{
    // NOTE: would've been better to implement using pairs
    std::vector<int> _priorities; // stores the priorities of the strings
    std::vector<T> _keys; // stores the strings in the same index as their associated priorities
    
    public:
        MinHeap() = default; // default constructor
        size_t getParent(size_t child); // get index of parent
        size_t getLeftChild(size_t parent); // get index of left child
        size_t getRightChild(size_t parent); // get index of right child
        void heapifyUp(); // after adding a node, heapify up
        void heapifyDown(); // after removal of node, heapify down
        T peek(); // returns the min
        size_t getMinPriority();
        size_t size(); // gets the size
        void add(T key, int priority);
        void remove(); // remove from the top of the heap
        bool empty(); // returns if the heap if empty
        void print();
        size_t getMinPriorityIndex(size_t first, size_t second); // returns the minimum priority between two indices

};

#include "minheap.tpp"