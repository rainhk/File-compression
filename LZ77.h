#pragma once
#include <vector>
#include <cstdint>

class LZ77{
    private:
    int offset = 0;
    int length = 0;
    char nextChar;
    const int windowSize = 256;
    int start = 0;
    public:
        std::vector<uint8_t> lz77Encode(
            const std::vector<uint8_t>& input
        );

        std::vector<uint8_t> lz77Decode(
            const std::vector<uint8_t>& input
        );
};