#include <iostream>

#include "huffman.h"

int main(){
    std::string filename = "/Users/mathewjacob/dev/cppprojects/HuffmanTree/data/war-and-peace.txt";
    HuffmanTree huff(filename);
    HuffmanTree copy(huff);
    std::cout << "BUILT HUFFMAN TREE\n";
    // std::cout << huff;
    // std::cout << huff.isEmpty() << std::endl;
    // std::cout << huff.encode("I like eating food a lot■") << std::endl; // ■ is a pseduo-EOF because the encoding without it may not be 0 mod 8 bits
    std::string pseudoEOF = huff.encodeMessage("hello, this is a hostile takeover"); // our pseudoEOF delimiter
    // std::cout << pseudoEOF << std::endl;
    // std::cout << huff.decodeMessage(pseudoEOF) << std::endl;
    std::cout << pseudoEOF << std::endl;
    std::cout << copy.decodeMessage(pseudoEOF) << std::endl;
    std::string s("001100010000100000111");
    std::cout << "EFFICIENCY: USES " << (sizeof("hello") - sizeof(s) / 8.0 )/ sizeof("hello") << " LESS SPACE\n";
}