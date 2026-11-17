// LZ77 -> huffman -> zip -> huffman -> LZ77
// g++ -std=c++17 *.cpp -o compressor
// ./compressor

#include <iostream>
#include <fstream>
#include "LZ77.h"
#include "test.h"

using namespace std;

// Need later to read file 

// vector<uint8_t> readFile(const string& filename) {
//     ifstream file(filename, ios::binary);

//     if (!file) {
//         throw runtime_error("Cannot open file: " + filename);
//     }

//     vector<uint8_t> data(
//         (istreambuf_iterator<char>(file)),
//         istreambuf_iterator<char>()
//     );

//     return data;
// }

int main() {
    LZ77 lzcompressor;

    try {
    runTests();

    } catch (const exception& e) {
        cerr << "[FAIL] " << e.what() << '\n';
        return 1;
    }

    return 0;

}