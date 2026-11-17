#include "LZ77.h"
#include <iostream>
using namespace std;

std::vector<uint8_t> LZ77::lz77Encode(const std::vector<uint8_t>& input){
    // 반복적으로 나오는 문자열을 압축핢..
    // Lookahead Buffer와 Search Buffer
    // Search Buffer | Lookahead Buffer
    // lz77 -> huffman = deflate algorithm
    // [max(0,i-window size), i-1]
    // start with 256kb window size

    // How to get longest match?
    // How to know if there is more match?

    // offset - 문자열의 시작점까지 이동해야하는 거리수
    // length - 오프셋 위치로부터 복사해와야할 자릿수
    // nextChar

    std::vector<uint8_t> output;
    int tempOffset = 0;
    int tempLength = 0;
    int offset = 0;
    int length = 0;
    for(int i = 0; i < input.size(); i++){
        if (i > windowSize){
            start = i - windowSize;
        }
        for(int j = start; j < i; j++){

            int cnt = j;
            int cnt2 = i;
            tempOffset = j;
            while (cnt2 < input.size() && tempLength < matchMax && input[cnt] == input[cnt2]) {
                cnt++;
                cnt2++;
                tempLength++;
            }
            if(length < tempLength){
                length = tempLength;
                offset = tempOffset;
            }
            tempLength = 0;
            tempOffset = 0;

        }
        if(length >= matchMin){
            // match
            output.insert(output.end(), 1);
            output.insert(output.end(), i - offset);
            output.insert(output.end(), length);
            i = i+length-1;
            length = 0;
        }
        else{
            // literal
            output.insert(output.end(), 0);
            output.insert(output.end(), input[i]);
        }
        
    }
    return output;
};

std::vector<uint8_t> LZ77::lz77Decode(const std::vector<uint8_t>& input){
    std::vector<uint8_t> output;
    cout << "hello" << endl;
    // literal 0
    // match 1

    // literal 이 1 일경우의수..
    // 흠.. literal match 구분..
    // literal 이 0 일수도있는데..

    for(uint8_t i : input){
        if(i == 1){
            cout << "1" << endl;
        }
        else{
            
        }
        
        cout << i << endl;
    }
    cout << input.size() << endl;

    return output;
}
