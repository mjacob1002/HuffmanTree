#include "binary_reader.h"


BinaryReader::BinaryReader(std::string filename) : _filename(filename){
    _ifs.open(filename, std::ios::in | std::ios::binary); // open the file as bionary
    if(_ifs.fail())
        throw std::runtime_error("Couldn't open the file " + filename);   
}

void BinaryReader::getCharsFromFile(){
    _ifs.seekg(0, std::ios::beg); // start at the beginning of the file
    char c;
    while(_ifs.read(&c, sizeof(c))){ // while we haven't reached the end of the file
        characters.push_back(c);
    }
}

std::string BinaryReader::byteToBinary(char byte){
    std::string byte_in_binary = "";
    char get_first_bit = 0x80; 
    for(int i = 0; i < 8; ++i){
        bool first_bit = byte & get_first_bit; // gets the first bit
        // std::cout << first_bit;
        if(first_bit)
            byte_in_binary += "1";
        else
            byte_in_binary += "0";
        byte <<= 1; // left-shift and get rid of the bit we already read
    }
    return byte_in_binary;
}

std::string BinaryReader::getBinary(){
    std::string binary_representation = "";
    for(char ch : characters){
        binary_representation += byteToBinary(ch);
    }
    return binary_representation;
}

std::string BinaryReader::readFromFile(){
    getCharsFromFile();
    return getBinary();
}

void BinaryReader::close(){
    _ifs.close();
}

std::vector<char> BinaryReader::getVector(){
    return characters;
}