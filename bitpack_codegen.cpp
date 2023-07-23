#include <cstdio>
#include <cmath>

constexpr int MaxNumBits = 8; // We're just comparing to Ultrapack, which only goes up to 256 distinct values. 

// This code is simpler than the usual bitpacking that goes up to 32 bits because we are guaranteed
// to only ever use up to 8 bytes
void WriteCompressFunction(std::FILE *file, int num_bits)
{
    constexpr int num_packed_together = 8;
    std::fprintf(file, R"(
// Pack %d elements using %d bytes
void Bitpack_Compress%d(const uint32_t **input, uint8_t **output)
{
    uint64_t group = 0;
)", num_packed_together, num_bits, num_bits);
    for(int ielement = 0; ielement < num_packed_together; ielement++)
    {
        int shift = ielement * num_bits;
        std::fprintf(file, "    group |= ((uint64_t)((*input)[%d])) << %d;\n", ielement, shift);
    }
    std::fprintf(file, "    *((uint64_t *)(*output)) = group;\n");
    std::fprintf(file, "    *output += %d;\n", num_bits);;
    std::fprintf(file, "    *input += %d;\n", num_packed_together);
    std::fprintf(file, "}\n");
}

void WriteDecompressFunction(std::FILE *file, int num_bits)
{
    constexpr int num_packed_together = 8;
    std::fprintf(file, R"(
// Unpack %d bytes into %d elements
void Bitpack_Decompress%d(const uint8_t **input, uint32_t **output)
{
    const uint64_t mask = (1 << %d) - 1;
    uint64_t group = *((uint64_t *)(*input));
)", num_bits, num_packed_together, num_bits);
    for(int ielement = 0; ielement < num_packed_together; ielement++)
    {
        int shift = ielement * num_bits;
        std::fprintf(file, "    (*output)[%d] = (group >> %d) & mask;\n", ielement, shift);
    }
    std::fprintf(file, "    *input += %d;\n", num_bits);
    std::fprintf(file, "    *output += %d;\n", num_packed_together);
    std::fprintf(file, "}\n");
}

void AddCompressFunctionToTable(FILE *file, int i)
{
    std::fprintf(file, "    Bitpack_Compress%d,\n", 32 - __builtin_clz(i - 1));
}

void AddDecompressFunctionToTable(FILE *file, int i)
{
    std::fprintf(file, "    Bitpack_Decompress%d,\n", 32 - __builtin_clz(i - 1));
}

int main()
{
    std::FILE *file = std::fopen("bitpack.h", "w");
    std::fprintf(file,
R"(#pragma once

#include <cstdint>
)");

    for(int num_bits = 1; num_bits <= MaxNumBits; num_bits++)
        WriteCompressFunction(file, num_bits);

    for(int num_bits = 1; num_bits <= MaxNumBits; num_bits++)
        WriteDecompressFunction(file, num_bits);

    std::fprintf(file, R"(
typedef void (*CompressFn)(const uint32_t **, uint8_t **);
CompressFn BitpackCompress[] =
{
    0,
    0,
)");
    for(int i = 2; i <= (1 << MaxNumBits); i++)
        AddCompressFunctionToTable(file, i);
    std::fprintf(file, R"(
};
typedef void (*DecompressFn)(const uint8_t **, uint32_t **);
DecompressFn BitpackDecompress[] =
{
    0,
    0,
)");
    for(int i = 2; i <= (1 << MaxNumBits); i++)
        AddDecompressFunctionToTable(file, i);
    std::fprintf(file, "};\n");

    std::fclose(file);
    return 0;
}
