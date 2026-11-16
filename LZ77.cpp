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
    int tempMatch = 0;
    int tempLength = 0;
    int offset = 0;
    int length = 0;
    cout << "LZ77" << endl; // check the function is working
    for(int i = 0; i < input.size(); i++){
        if (i > windowSize){
            start = i - windowSize;
        }
        for(int j = start; j < i; j++){

            // 처음 match 부터 몇개나 현재 i 까지 동일한지
            while (true)
            {
                /* code */
            }
            
            if(input[i] == input[j]){
                if(tempMatch == 0){
                    tempMatch = j;
                }
                tempLength++;
                if(tempLength > length){
                    length = tempLength;
                    offset = tempMatch;
                }
            }
            else{
                if(tempLength >= length){
                    length = tempLength;
                    offset = tempMatch;
                }
                tempMatch = 0;
                tempLength = 0;
            }
        }
        cout << tempMatch << endl;
        cout << tempLength << endl;
        if(tempMatch == 0){
            if(length > 0){
                output.insert(output.end(), offset);
                cout << offset << endl;
                output.insert(output.end(), length);
            }
            else{
                output.insert(output.end(), input[i]);
            }
            
        }
        
    }

    for(auto i:output){
        cout << i << endl;
    }
    return output;
};

std::vector<uint8_t> LZ77::lz77Decode(const std::vector<uint8_t>& input){

}
