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
    static constexpr char pEOF = '\xe2'; // pseudoEOF as a character
    std::string pEOF_encoded; // the encoding of the pEOF in Huffman coding; don't think I need this
    void print(std::ostream& os, HuffNode* currRoot) const;

    std::unordered_map<char, int> getFrequencyTable(std::string filename); // read from this file and generate frequency table of characters 
    HuffNode* buildTree(MinHeap<HuffNode*>& priority_queue); // return the root of the Huffman tree
    std::string encode(const std::string&) const; // encodes a message using the current huffman tree and returns the encoding
    void _clean(HuffNode* currRoot); // takes care of freeing all the huffnodes
    void _copy(HuffNode*&, const HuffNode*);
    public:
        HuffmanTree(std::string keyFile); // construct a HuffmanTree from a file key
        std::string decodeFile(std::string filename); // decode the string from a filename
        std::string encodeMessage(const std::string& ) const; // public method used for encoding messages
        void encodeToFile(std::string message, std::string filename); // encodes a message using huffman tree and outputs to a file
        friend std::ostream& operator<<(std::ostream& os, const HuffmanTree& rhs);
        bool isEmpty(){return !_root;}
        std::string decodeMessage(const std::string& binary) const;
        ~HuffmanTree(); // destructor of a HuffmanTree
        HuffmanTree(const HuffmanTree& other);
        HuffmanTree& operator=(const HuffmanTree& rhs);
        HuffmanTree(HuffmanTree&&); // r-value
        HuffmanTree& operator=(HuffmanTree&& rhs)
};