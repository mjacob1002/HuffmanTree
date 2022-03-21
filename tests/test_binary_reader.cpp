#include "catch.hpp"
#include "binary_reader.h"


bool readUWUtest(){
    BinaryReader br("bin_read_test.bin");
    std::string binary = br.readFromFile();
    auto c = br.getVector();
    for(auto ch : c)
        std::cout << ch;
    // std::cout << "BINARY REPRESENTATION: " << binary;
    std::cout << "\n BINARY REPRESENTATION: " << binary << std::endl;
    return (binary == "011101010111011101110101");
}

int main(){
    std::cout << "readUWUtest is commencing:";
    // assert(readUWUtest() == true);
    bool matches = readUWUtest();
    if(matches) std::cout << "MATCHES THE CORRECT OUTPUT";
    else {
        std::cout << "WAS SUPPOSED TO OUTPUT THIS: 011101010111011101110101";
    }
    std::cout << std::endl;
    
}