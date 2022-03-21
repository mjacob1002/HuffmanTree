#include "catch.hpp"
#include "huffman.h"

TEST_CASE("Binary Writer tests"){
    BinaryWriter bw("test_write");
    bw.writeByte(char('u'));
}