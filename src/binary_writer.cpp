#include "binary_writer.h"
#include <stdexcept>
BinaryWriter::BinaryWriter(std::string filename) : _fileName(filename) {
    _ofs.open(_fileName, std::ios::binary); // write to a binary file
    _ofs.seekp(0, std::ios::end);
    if(_ofs.fail() || !_ofs.is_open())
        throw std::runtime_error("BINARY WRITER FAILURE: COULDN'T OPEN " + _fileName);
}

void BinaryWriter::writeMessage(std::vector<char> message){
    for(char& ch : message){
        writeByte(ch);
    }
}

void BinaryWriter::writeByte(char to_write){
    _ofs.write(&to_write, sizeof(to_write));
}


void BinaryWriter::close(){
    _ofs.close();
}