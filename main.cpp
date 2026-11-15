// LZ77 -> huffman -> zip -> huffman -> LZ77
// g++ -std=c++17 *.cpp -o compressor
// ./compressor

#include <iostream>
#include <fstream>
#include "LZ77.h"

using namespace std;

int main() {
    LZ77 lzcompressor;

    // ofstream myfile;
    // myfile.open ("sample.txt", ios::out | ios::app | ios::binary);
    // myfile << "Writing this to a file.\n";
    // myfile.close();

    vector<uint8_t> test = {
    0b01100001,  // a
    0b01100010,  // b
    0b01100011,  // c
    0b01100001,  // a
    0b01100010,  // b
    0b01100011   // c
    };

    lzcompressor.lz77Encode(test);

    return 0;

}