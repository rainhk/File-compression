// referred Deflate format

// file format
// Input -> vector<uint8_t>
// Output -> vector<uint8_t>
// Literal Tag(0) 1byte, Value 1byte
// Match Tag(1) 1byte, Distance or Offset 2bytes, Length 2bytes