#include <vector>

// check repeated single bytes ex: aaaaaaaaaa

// lz77 sample ourput
// Literial = 00000000
// Match = 00000001
std::vector<uint8_t> lz77Output1 = {
    0b00000000, 0b01001000,  // H
    0b00000000, 0b01100101,  // e
    0b00000000, 0b01101100,  // l
    0b00000000, 0b01101100,  // l
    0b00000000, 0b01101111,  // o
    0b00000000, 0b00100000,  // space
    0b00000000, 0b01000011,  // C
    0b00000000, 0b00100000,  // space
    0b00000000, 0b01010111,  // W
    0b00000000, 0b01101111,  // o
    0b00000000, 0b01110010,  // r
    0b00000000, 0b01101100,  // l
    0b00000000, 0b01100100   // d
};

std::vector<uint8_t> lz77Output2 = {
    0b00000000, 0b01100001,  // Literal(a)
    0b00000000, 0b01100010,  // Literal(b)
    0b00000000, 0b01100011,  // Literal(c)
    0b00000001,              // Match
    0b00000000, 0b00000011,  // Distance = 3
    0b00000000, 0b00000110   // Length = 6
};