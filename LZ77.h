#pragma once
#include <vector>
#include <cstdint>

class LZ77{
    private:

    char nextChar;
    const int windowSize = 4096;
    const int matchMax = 258; // Deflate
    const int matchMin = 3;
    int start = 0;
    
    public:
        std::vector<uint8_t> lz77Encode(
            const std::vector<uint8_t>& input
        );

        std::vector<uint8_t> lz77Decode(
            const std::vector<uint8_t>& input
        );
};