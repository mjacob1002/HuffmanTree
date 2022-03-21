// #include "catch.hpp"
#include "binary_writer.h"
#include <iostream>

std::vector<char> readBytes(std::string filename){
    std::vector<char> bytes;
    std::ifstream ifs;
    ifs.open(filename, std::ios::binary | std::ios::in);
    char c = '\0';
    while(ifs.read(&c, sizeof(c))){ // while we haven't reached the end of the file
        bytes.push_back(c);
    }
    return bytes;
}

void testBinaryWriteByte(){
   BinaryWriter bw("bin_write.bin");
   std::cout << "WRITING BYTES\n";
   bw.writeByte('u');
   bw.writeByte('w');
   bw.writeByte('u');
   bw.close();
   std::cout << "DONE WRITING BYTES\n";
   auto characters = readBytes("bin_write.bin");
   for(auto ch : characters)
    std::cout << ch << " ";
}

void testBinaryWriteMessage(){
    BinaryWriter bw("bin_write");
    bw.writeMessage(std::vector<char>{'h', 'e', 'l', 'l', 'o'});
    bw.close();
    auto characters = readBytes("bin_write");
    for(auto ch : characters)
        std::cout << ch;
}

int main(){
    testBinaryWriteByte();
    std::cout << std::endl;
    testBinaryWriteMessage();

    // for(size_t i = 0; i < 10000000000; ++i){ // for using \r to write cool text interfaces
    //     std::cout << i << "/10000000000\r";
    //     std::cout.flush();
    // }
}