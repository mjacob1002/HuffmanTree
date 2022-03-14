#include <iostream>

#include "huffman.h"

int main(){
    std::string filename = "/Users/mathewjacob/dev/cppprojects/HuffmanTree/data/war-and-peace.txt";
    HuffmanTree huff(filename);
    std::cout << "BUILT HUFFMAN TREE\n";
    // std::cout << huff;
    // std::cout << huff.isEmpty() << std::endl;
    std::cout << huff.encode("hello") << std::endl;
    std::cout << huff.decodeMessage("001100010000100000111") << std::endl;
    std::string s("001100010000100000111");
    std::cout << "EFFICIENCY: USES " << (sizeof("hello") - sizeof(s) / 8.0 )/ sizeof("hello") << " LESS SPACE\n";
}