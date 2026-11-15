#include "LZ77.h"
#include <iostream>
using namespace std;

std::vector<uint8_t> LZ77::lz77Encode(const std::vector<uint8_t>& input){
    // 반복적으로 나오는 문자열을 압축핢..
    // Lookahead Buffer와 Search Buffer
    // lz77 -> huffman = deflate algorithm

    const std::vector<uint8_t> output;
    cout << "hello" << endl;
    for(auto i : input){
        cout << i << endl;
    }
    return output;
};

std::vector<uint8_t> LZ77::lz77Decode(const std::vector<uint8_t>& input){

}
