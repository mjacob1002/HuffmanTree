#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

class BinaryReader{
    std::ifstream _ifs; // reads from binary file
    std::string _filename; // file to read from
    std::vector<char> characters;
    public:
        BinaryReader(std::string);
        std::string byteToBinary(char); // converts a characters to a string of 1s and 0s
        void getCharsFromFile(); // puts the chars from binary file to characters vector
        std::string getBinary();
        std::string readFromFile();
        std::vector<char> getVector();
        void close();
};