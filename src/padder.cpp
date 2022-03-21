#include "padder.h"

Padder::Padder(std::string input){
    for(auto& ch: input){
        if(ch == '1'){
            writeBit(1);
        } else{
            writeBit(0);
        }
    }
}


void Padder::writeBit(bool bit){
    current_char <<= 1; // bit-shift left one, make space for the bit to set
    if(bit){ // if the bit is one, then set the LSB to 1 with bitmask; if it is 0, then LSB will be 0 from the bit shift
        current_char |= 0x01; // 
    }
    current_bit++; // add one to the current amount of bits set
    if(current_bit == 8){ // if already hit the max size of a char, reset the current_char
        characters.push_back(current_char);
        current_bit = 0;
        current_char = '\0';
    }
}

std::vector<char> Padder::getChars(){return characters;}