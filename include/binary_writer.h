#pragma once
#include <fstream>
#include <iostream>
#include <vector>
class BinaryWriter{

    std::string _fileName;
    std::ofstream _ofs;
    static constexpr char get_first_bit_mask = 0x80; // this is 0b10000000
    public:
        BinaryWriter(std::string filename); // constructor
        void writeMessage(std::vector<char>); // take a vector of chars and writes them to binary file
        void writeByte(char); // write an individual byte to binary file
        void close();
};