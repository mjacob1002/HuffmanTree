using std::swap;

// helper that gets the parent index of any child inde
template<typename T>
size_t MinHeap<T>::getParent(size_t child){
    if(child % 2 == 0){
        return (child - 1) / 2; // 
    }
    return child / 2;
}
template<typename T>
size_t MinHeap<T>::getLeftChild(size_t parent){
    return 2 * parent + 1;
}
template<typename T>
size_t MinHeap<T>::getRightChild(size_t parent){
    return 2 * parent + 2;
}
// get the element at the top of the priority queue
template<typename T>
T MinHeap<T>::peek(){
    if(empty())
        return T();
    return _keys.at(0);
}
// gets the size of the priority queue
template<typename T>
size_t MinHeap<T>::size(){
    return _priorities.size();
}
// boolean flag of whether the queue is empty
template<typename T>
bool MinHeap<T>::empty(){
    return size() == 0;
}
// add a string with a given priority to the queue
template<typename T>
void MinHeap<T>::add(T key, int priority){
    _keys.push_back(key);
    _priorities.push_back(priority);
    heapifyUp();
}
// remove the current minimum from the priority queue
template<typename T>
void MinHeap<T>::remove(){
    if(empty()) return;
    _keys.at(0) = _keys.back(); // put the element last put in in the root of the heap
    _priorities.at(0) = _priorities.back(); // put the element last put in in the root of the heap
    _keys.pop_back();
    _priorities.pop_back();
    heapifyDown(); // maintain the heap property of the priority queue
}

// heapify from the leftmost child
template<typename T>
void MinHeap<T>::heapifyUp(){
    size_t curr_index = size() - 1; // the farthest right element of last level
    while(curr_index){ // curr_index = 0 is the root, which doesn't have a parent
        size_t parent = getParent(curr_index); // the parent of the current element
        if(_priorities.at(parent) <= _priorities.at(curr_index)) // the child >= parent, MinHeap<T> is maintained
            return;
        swap(_priorities.at(parent), _priorities.at(curr_index)); // swap both the priorities and keys
        swap(_keys.at(parent), _keys.at(curr_index));
        curr_index = parent; // reassign the current node to parent and continue to heapify
    }
}

template<typename T>
void MinHeap<T>::heapifyDown(){
    size_t curr = 0;
    while(getLeftChild(curr) < size()){ // if the left child would be greater than the current size, then we are on the last level
        size_t minOfChildren = getMinPriorityIndex(getLeftChild(curr), getRightChild(curr)); // gets the minimum priority between left and right child
        if(_priorities.at(curr) <= _priorities.at(minOfChildren)) return; // nothing to do if parent is <= min of children
        swap(_priorities.at(curr), _priorities.at(minOfChildren));
        swap(_keys.at(curr), _keys.at(minOfChildren));
        curr = minOfChildren;
    }
}

template<typename T>
size_t MinHeap<T>::getMinPriorityIndex(size_t first, size_t second){
    if(first >= size() && second >= size()) return -1;
    else if (first >= size()) return second;
    else if (second >= size()) return first;
    
    if(_priorities.at(first) > _priorities.at(second)) return second;
    return first; // first will always be returned if first and second have same priority
}

template<typename T>
void MinHeap<T>::print(){
    std::queue<size_t> indices;
    indices.push(0);
    while(!indices.empty()){ // level traversal
        size_t curr_idx = indices.front();
        indices.pop();
        std::cout << "[" << _keys.at(curr_idx) << ":" << _priorities.at(curr_idx) << "], "; // print the current index
        if(getLeftChild(curr_idx) < size()) // if the left child is valid, add it to the queue to be processed
            indices.push(getLeftChild(curr_idx));
        if(getRightChild(curr_idx) < size()) // if the right child is valid, add it to the queue
            indices.push(getRightChild(curr_idx));
    }
}

template<typename T>
size_t MinHeap<T>::getMinPriority(){
    // TODO: handle the case when priority queue is empty
    return _priorities.at(0);
}