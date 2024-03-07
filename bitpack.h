#pragma once

#include <cstdint>

// Pack 8 elements using 1 bytes
void Bitpack_Compress1(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 1;
    group |= ((uint64_t)((*input)[2])) << 2;
    group |= ((uint64_t)((*input)[3])) << 3;
    group |= ((uint64_t)((*input)[4])) << 4;
    group |= ((uint64_t)((*input)[5])) << 5;
    group |= ((uint64_t)((*input)[6])) << 6;
    group |= ((uint64_t)((*input)[7])) << 7;
    *((uint64_t *)(*output)) = group;
    *output += 1;
    *input += 8;
}

// Pack 8 elements using 2 bytes
void Bitpack_Compress2(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 2;
    group |= ((uint64_t)((*input)[2])) << 4;
    group |= ((uint64_t)((*input)[3])) << 6;
    group |= ((uint64_t)((*input)[4])) << 8;
    group |= ((uint64_t)((*input)[5])) << 10;
    group |= ((uint64_t)((*input)[6])) << 12;
    group |= ((uint64_t)((*input)[7])) << 14;
    *((uint64_t *)(*output)) = group;
    *output += 2;
    *input += 8;
}

// Pack 8 elements using 3 bytes
void Bitpack_Compress3(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 3;
    group |= ((uint64_t)((*input)[2])) << 6;
    group |= ((uint64_t)((*input)[3])) << 9;
    group |= ((uint64_t)((*input)[4])) << 12;
    group |= ((uint64_t)((*input)[5])) << 15;
    group |= ((uint64_t)((*input)[6])) << 18;
    group |= ((uint64_t)((*input)[7])) << 21;
    *((uint64_t *)(*output)) = group;
    *output += 3;
    *input += 8;
}

// Pack 8 elements using 4 bytes
void Bitpack_Compress4(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 4;
    group |= ((uint64_t)((*input)[2])) << 8;
    group |= ((uint64_t)((*input)[3])) << 12;
    group |= ((uint64_t)((*input)[4])) << 16;
    group |= ((uint64_t)((*input)[5])) << 20;
    group |= ((uint64_t)((*input)[6])) << 24;
    group |= ((uint64_t)((*input)[7])) << 28;
    *((uint64_t *)(*output)) = group;
    *output += 4;
    *input += 8;
}

// Pack 8 elements using 5 bytes
void Bitpack_Compress5(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 5;
    group |= ((uint64_t)((*input)[2])) << 10;
    group |= ((uint64_t)((*input)[3])) << 15;
    group |= ((uint64_t)((*input)[4])) << 20;
    group |= ((uint64_t)((*input)[5])) << 25;
    group |= ((uint64_t)((*input)[6])) << 30;
    group |= ((uint64_t)((*input)[7])) << 35;
    *((uint64_t *)(*output)) = group;
    *output += 5;
    *input += 8;
}

// Pack 8 elements using 6 bytes
void Bitpack_Compress6(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 6;
    group |= ((uint64_t)((*input)[2])) << 12;
    group |= ((uint64_t)((*input)[3])) << 18;
    group |= ((uint64_t)((*input)[4])) << 24;
    group |= ((uint64_t)((*input)[5])) << 30;
    group |= ((uint64_t)((*input)[6])) << 36;
    group |= ((uint64_t)((*input)[7])) << 42;
    *((uint64_t *)(*output)) = group;
    *output += 6;
    *input += 8;
}

// Pack 8 elements using 7 bytes
void Bitpack_Compress7(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 7;
    group |= ((uint64_t)((*input)[2])) << 14;
    group |= ((uint64_t)((*input)[3])) << 21;
    group |= ((uint64_t)((*input)[4])) << 28;
    group |= ((uint64_t)((*input)[5])) << 35;
    group |= ((uint64_t)((*input)[6])) << 42;
    group |= ((uint64_t)((*input)[7])) << 49;
    *((uint64_t *)(*output)) = group;
    *output += 7;
    *input += 8;
}

// Pack 8 elements using 8 bytes
void Bitpack_Compress8(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
    group |= ((uint64_t)((*input)[0])) << 0;
    group |= ((uint64_t)((*input)[1])) << 8;
    group |= ((uint64_t)((*input)[2])) << 16;
    group |= ((uint64_t)((*input)[3])) << 24;
    group |= ((uint64_t)((*input)[4])) << 32;
    group |= ((uint64_t)((*input)[5])) << 40;
    group |= ((uint64_t)((*input)[6])) << 48;
    group |= ((uint64_t)((*input)[7])) << 56;
    *((uint64_t *)(*output)) = group;
    *output += 8;
    *input += 8;
}

// Unpack 1 bytes into 8 elements
void Bitpack_Decompress1(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 1) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 1) & mask;
    (*output)[2] = (group >> 2) & mask;
    (*output)[3] = (group >> 3) & mask;
    (*output)[4] = (group >> 4) & mask;
    (*output)[5] = (group >> 5) & mask;
    (*output)[6] = (group >> 6) & mask;
    (*output)[7] = (group >> 7) & mask;
    *input += 1;
    *output += 8;
}

// Unpack 2 bytes into 8 elements
void Bitpack_Decompress2(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 2) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 2) & mask;
    (*output)[2] = (group >> 4) & mask;
    (*output)[3] = (group >> 6) & mask;
    (*output)[4] = (group >> 8) & mask;
    (*output)[5] = (group >> 10) & mask;
    (*output)[6] = (group >> 12) & mask;
    (*output)[7] = (group >> 14) & mask;
    *input += 2;
    *output += 8;
}

// Unpack 3 bytes into 8 elements
void Bitpack_Decompress3(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 3) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 3) & mask;
    (*output)[2] = (group >> 6) & mask;
    (*output)[3] = (group >> 9) & mask;
    (*output)[4] = (group >> 12) & mask;
    (*output)[5] = (group >> 15) & mask;
    (*output)[6] = (group >> 18) & mask;
    (*output)[7] = (group >> 21) & mask;
    *input += 3;
    *output += 8;
}

// Unpack 4 bytes into 8 elements
void Bitpack_Decompress4(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 4) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 4) & mask;
    (*output)[2] = (group >> 8) & mask;
    (*output)[3] = (group >> 12) & mask;
    (*output)[4] = (group >> 16) & mask;
    (*output)[5] = (group >> 20) & mask;
    (*output)[6] = (group >> 24) & mask;
    (*output)[7] = (group >> 28) & mask;
    *input += 4;
    *output += 8;
}

// Unpack 5 bytes into 8 elements
void Bitpack_Decompress5(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 5) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 5) & mask;
    (*output)[2] = (group >> 10) & mask;
    (*output)[3] = (group >> 15) & mask;
    (*output)[4] = (group >> 20) & mask;
    (*output)[5] = (group >> 25) & mask;
    (*output)[6] = (group >> 30) & mask;
    (*output)[7] = (group >> 35) & mask;
    *input += 5;
    *output += 8;
}

// Unpack 6 bytes into 8 elements
void Bitpack_Decompress6(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 6) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 6) & mask;
    (*output)[2] = (group >> 12) & mask;
    (*output)[3] = (group >> 18) & mask;
    (*output)[4] = (group >> 24) & mask;
    (*output)[5] = (group >> 30) & mask;
    (*output)[6] = (group >> 36) & mask;
    (*output)[7] = (group >> 42) & mask;
    *input += 6;
    *output += 8;
}

// Unpack 7 bytes into 8 elements
void Bitpack_Decompress7(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 7) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 7) & mask;
    (*output)[2] = (group >> 14) & mask;
    (*output)[3] = (group >> 21) & mask;
    (*output)[4] = (group >> 28) & mask;
    (*output)[5] = (group >> 35) & mask;
    (*output)[6] = (group >> 42) & mask;
    (*output)[7] = (group >> 49) & mask;
    *input += 7;
    *output += 8;
}

// Unpack 8 bytes into 8 elements
void Bitpack_Decompress8(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << 8) - 1;
    uint64_t group = *((uint64_t *)(*input));
    (*output)[0] = (group >> 0) & mask;
    (*output)[1] = (group >> 8) & mask;
    (*output)[2] = (group >> 16) & mask;
    (*output)[3] = (group >> 24) & mask;
    (*output)[4] = (group >> 32) & mask;
    (*output)[5] = (group >> 40) & mask;
    (*output)[6] = (group >> 48) & mask;
    (*output)[7] = (group >> 56) & mask;
    *input += 8;
    *output += 8;
}

typedef void (*CompressFn)(const uint32_t **, uint8_t **);
CompressFn BitpackCompress[] =
{
    0,
    0,
    Bitpack_Compress1,
    Bitpack_Compress2,
    Bitpack_Compress2,
    Bitpack_Compress3,
    Bitpack_Compress3,
    Bitpack_Compress3,
    Bitpack_Compress3,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress4,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress5,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress6,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress7,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,
    Bitpack_Compress8,

};
typedef void (*DecompressFn)(const uint8_t **, uint32_t **);
DecompressFn BitpackDecompress[] =
{
    0,
    0,
    Bitpack_Decompress1,
    Bitpack_Decompress2,
    Bitpack_Decompress2,
    Bitpack_Decompress3,
    Bitpack_Decompress3,
    Bitpack_Decompress3,
    Bitpack_Decompress3,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress4,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress5,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress6,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress7,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
    Bitpack_Decompress8,
};
