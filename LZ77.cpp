#include "LZ77.h"
#include <iostream>
using namespace std;

std::vector<uint8_t> LZ77::lz77Encode(const std::vector<uint8_t>& input){
    // 반복적으로 나오는 문자열을 압축핢..
    // Lookahead Buffer와 Search Buffer
    // lz77 -> huffman = deflate algorithm
    // [max(0,i-window size), i-1]
    // start with 256kb window size

    // How to get longest match?
    // How to know if there is more match?

    std::vector<uint8_t> output;
    cout << "hello" << endl;
    for(int i = 0; i < input.size(); i++){
        if (i > windowSize){
            start = i - windowSize;
        }
        for(int j = start; j < i; j++){
            
        }
        output.insert(output.end(), input[i]);
    }


    for(auto i:output){
        cout << i << endl;
    }
    return output;
};

std::vector<uint8_t> LZ77::lz77Decode(const std::vector<uint8_t>& input){

}
