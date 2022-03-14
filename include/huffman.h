#include "minheap.h"
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <unordered_set>

class HuffmanTree{
    struct HuffNode{ // used for building the tree
        std::string value;
        HuffNode* left = nullptr;
        HuffNode* right = nullptr;
        std::unordered_set<char> characters;
        HuffNode(std::string val) : value(val){
            for(auto& ch : val){
                characters.insert(ch);
            }
        }
        bool contains(char s){
            return characters.count(s) == 1;
        }
    };
    HuffNode* _root; // root of the huffman tree
    public:
        HuffmanTree(std::string keyFile); // construct a HuffmanTree from a file key
        std::string decode(std::string filename); // decode the string from a filename
        std::unordered_map<char, int> getFrequencyTable(std::string filename); // read from this file and generate frequency table of characters 
        HuffNode* buildTree(MinHeap<HuffNode*>& priority_queue); // return the root of the Huffman tree
        std::string encode(const std::string& message) const; // encodes a message using the current huffman tree and returns the encoding
        // void encodeToFile(std::string message, std::string filename); // encodes a message using huffman tree and outputs to a file
        void print(std::ostream& os, HuffNode* currRoot) const;
        friend std::ostream& operator<<(std::ostream& os, const HuffmanTree& rhs);
        bool isEmpty(){return !_root;}
        std::string decodeMessage(const std::string& binary) const;
};