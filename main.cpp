// LZ77 -> huffman -> zip -> huffman -> LZ77
// g++ -std=c++17 *.cpp -o compressor
// ./compressor

#include <iostream>
#include <fstream>
#include "LZ77.h"

using namespace std;

vector<uint8_t> readFile(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        throw runtime_error("Cannot open file: " + filename);
    }

    vector<uint8_t> data(
        (istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>()
    );

    return data;
}

int main() {
    LZ77 lzcompressor;

    std::vector<uint8_t> input = {
    0b01100001,  // a
    0b01100010,  // b
    0b01100011,  // c
    0b01100001,  // a
    0b01100010,  // b
    0b01100011,  // c
    0b01100001,  // a
    0b01100010,  // b
    0b01100011   // c
    };

    // 1. 파일을 Binary로 읽기
    // vector<uint8_t> input = readFile("lz77_test_120KB.txt");

    cout << "Original size: "
         << input.size() << " bytes\n";

    // 2. LZ77 Compressor에 전달
    vector<uint8_t> output = lzcompressor.lz77Encode(input);

    cout << "Compressed size: "
         << output.size() << " bytes\n";

    vector<uint8_t> output_2 = lzcompressor.lz77Decode(output);

    return 0;

}