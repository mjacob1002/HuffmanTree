#include <iostream>

#include "huffman.h"

int main(){
    std::string filename = "/Users/mathewjacob/dev/cppprojects/HuffmanTree/data/war-and-peace.txt";
    HuffmanTree huff(filename);
    huff.encodeToFile("This is a hostile takeover", "encoding.file");
    HuffmanTree copyOfHuff(huff);
    auto p = copyOfHuff.decodeFile("encoding.file");
    std::cout << p << std::endl;
}