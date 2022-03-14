#include "minheap.h"
#include <string>

int main(){
    MinHeap<std::string> mheap;
    mheap.add("falafel", 7);
    mheap.add("Zoe", 3);
    mheap.add("Tacos", 5);
    mheap.print();
    std::cout << "\n###########\n";
    mheap.add("Ava", 3);
    mheap.print();
    std::cout << "\n ######################## \n";
    mheap.remove();
    mheap.print();
}