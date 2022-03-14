#include "huffman.h"

#include <iostream>
#include<sstream>

std::unordered_map<char, int> HuffmanTree::getFrequencyTable(std::string filename){
    std::unordered_map<char, int> frequency_table; // hash map that will store frequencies
    std::ifstream ifs(filename); // filestreaming
    char current; // the current character being processed
    while(ifs.get(current)){
        // std::cout << "CURRENT CHAR: " << current << " \n";
        if(frequency_table.find(current) == frequency_table.end()) // not in the unordered map
            frequency_table[current] = 1;
        else
            frequency_table[current] += 1;
    }
    return frequency_table;
}

HuffmanTree::HuffmanTree(std::string keyFile){
    MinHeap<HuffNode*> mheap;
    std::cout << "HEAP CONSTRUCTED\n";
    std::unordered_map<char, int> frequency_table = getFrequencyTable(keyFile); // generate freq table
    std::unordered_map<std::string, HuffNode*> huff_table; // maps a string to its huffnode
    for(auto& it : frequency_table){
        std::string s = std::string("") + it.first;
        // std::cout << "STRING: " << s << std::endl;
        HuffNode* huff = new HuffNode(s); // pointer to HuffNode with a string
        mheap.add(huff, frequency_table[s[0]]); // add the HuffNode* pointer, with the frequency of its string, in the minHeap
    }
    std::cout << frequency_table.size() << std::endl;
    _root = buildTree(mheap); // assign the root of the huffman tree

}


typename HuffmanTree::HuffNode* HuffmanTree::buildTree(MinHeap<HuffNode*>& priority_queue){
    if(priority_queue.size() == 1){
        HuffNode* root =  priority_queue.peek(); // only one node, so that is our huffman tree
        return root;
    }
    HuffNode* root = nullptr; // the root of the current tree
    while(!priority_queue.empty() && priority_queue.size() != 1){
        HuffNode* first = priority_queue.peek();
        size_t first_priority = priority_queue.getMinPriority();
        priority_queue.remove();
        HuffNode* second = priority_queue.peek();
        size_t second_priority = priority_queue.getMinPriority();
        priority_queue.remove();
        root = new HuffNode(first -> value + second -> value); // create a new HuffNode with the string of the sum of the first and the sum of the second
        root -> left = first;
        root -> right = second;
        priority_queue.add(root, first_priority + second_priority); // reinsert the node into priority queue, with priority of sum of its children
    }
    return root;
}

std::string HuffmanTree::encode(const std::string& message) const{
    HuffNode* curr = _root;
    int curr_index = 0; // the current index of the message
    std::string sequence = "";
    while(curr_index < message.size()){
        char charac = message.at(curr_index); // observe the current character
        if(!curr -> left && !curr -> right) // at a leaf node, found the character, nothing else to observe, go back to root for next character
        {
            curr = _root;
            curr_index++;
            continue;
        }
        if(curr -> left && curr -> left -> contains(charac)){
            curr = curr -> left;
            sequence.append("0");
        } else {
            curr = curr -> right;
            sequence.append("1");
        }
        
    }
    return sequence;
}

void HuffmanTree::print(std::ostream& os, HuffNode* currRoot) const{
    if(!currRoot) return;
    print(os, currRoot -> left); // process the left subtree
    os << "["; // process the current node
    for(char c : currRoot -> value){
        if(c == '\n'){
            os << "\\n";
            continue;
        }
        os << c;
    }
    os << "], ";
    print(os, currRoot -> right); // process the right subtree
}


std::string HuffmanTree::decodeMessage(const std::string& binary) const{
    size_t curr_idx = 0;
    auto curr = _root;
    std::string message = ""; // stores the decoded message
    while(curr_idx < binary.size()){
        if(binary.at(curr_idx) == '0'){ // go left
            curr = curr -> left;
        } else {
            curr = curr -> right;
        }
        if(!curr -> left && !curr -> right){ // leaf node
            message += curr -> value;
            curr = _root;
        }
        curr_idx++;
    }
    return message;
}

std::ostream& operator<<(std::ostream& os, const HuffmanTree& rhs){
    rhs.print(os, rhs._root);
    return os;
}

