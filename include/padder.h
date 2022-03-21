#include <vector>
#include <string>

class Padder {
    std::vector<char> characters;
    char current_char = '\0'; // 00000000
    int current_bit = 0; // the amount of bits written
    public:
        Padder(std::string input);
        std::vector<char> getChars(); // getter
        void writeBit(bool bit); // writes a bit to the current character
        

};