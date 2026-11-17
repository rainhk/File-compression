
#include "LZ77.h"

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

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

void testLZ77(
    const string& name,
    const vector<uint8_t>& original
) {
    LZ77 lzcompressor;
    auto compressed = lzcompressor.lz77Encode(original);
    auto restored = lzcompressor.lz77Decode(compressed);

    if (original != restored) {
        throw runtime_error("LZ77 test failed: " + name);
    }

    cout << "[PASS] " << name
         << " | Original size: " << original.size()
         << " | Compressed size: " << compressed.size()
         << '\n';
}

void runTests() {
    cout << "\n=== LZ77 Tests ===\n";

    testLZ77("Empty", {});

    testLZ77("Single byte", {'a'});

    testLZ77("Simple repetition", {
        'a', 'b', 'c', 'a', 'b', 'c'
    });

    testLZ77("a repetition", {
        'a', 'a', 'a', 'a', 'a', 'a'
    });

    testLZ77("Overlapping match", {
        'a', 'b', 'c', 'a', 'b', 'c',
        'a', 'b', 'c', 'a', 'b', 'c'
    });

    testLZ77("Binary values", {
        0, 1, 2, 255, 0, 1, 2, 255
    });

    testLZ77("Repeated byte",
        vector<uint8_t>(1000, 'a')
    );

    testLZ77("File read" ,{
        readFile("lz77_test_120KB.txt")
    });

    cout << "=== All LZ77 tests passed ===\n\n";
}