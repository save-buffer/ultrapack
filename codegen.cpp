#include <algorithm>
#include <cstdio>
#include <cmath>

constexpr int NumValuesToCompute = 256;

int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a * (b / GCD(a, b));
}

struct UltrapackGrouping
{
    int elements_per_group;
    int bits_per_group;
};

UltrapackGrouping groupings[NumValuesToCompute + 1];

void ComputeMinBitsPerValue(std::FILE *file, int num_values)
{
    double bits_per_value = 10000;
    int bits_per_group = 0;
    int elts_per_group = 0;
    for(int num_bits_per_group = 1; num_bits_per_group <= 56; num_bits_per_group++)
    {
        for(int num_elts_per_group = 1; num_elts_per_group < 100; num_elts_per_group++)
        {
            if(log(2) * num_bits_per_group < log(num_values) * num_elts_per_group)
                break;
            double bpv = static_cast<double>(num_bits_per_group) / static_cast<double>(num_elts_per_group);
            if(bpv < bits_per_value - 0.05)
            {
                bits_per_value = bpv;
                bits_per_group = num_bits_per_group;
                elts_per_group = num_elts_per_group;
            }
        }
    }
    double bitpack_bits = static_cast<double>(32 - __builtin_clz(num_values - 1));
    double pct_savings = ((bitpack_bits - bits_per_value) / bitpack_bits) * 100.0;
#if 0
    std::printf(
        "%d: %d bits / %d values = %.4f bpv (vs %.4f bpv, %.2f%% savings)\n",
        num_values,
        bits_per_group,
        elts_per_group,
        bits_per_value,
        bitpack_bits,
        pct_savings);
#endif
    groupings[num_values] = { elts_per_group, bits_per_group };
    std::printf("%d, %.4f, %.4f, %.4f\n", num_values, bits_per_value, bitpack_bits, pct_savings);
    std::fprintf(
        file,
        "%s{ %2d, %2d },%s",
        num_values % 8 == 1 ? "    " : "",
        elts_per_group,
        bits_per_group,
        num_values % 8 == 0 ? "\n" : " ");
}

void WriteCompressFunction(std::FILE *file, int num_values)
{
    int num_bits = LCM(groupings[num_values].bits_per_group, 8);
    int num_groups = num_bits / groupings[num_values].bits_per_group;
    int num_bytes = num_bits / 8;
    std::fprintf(file, R"(// Pack %d groups using %d bytes (%d values total)
void Ultrapack_Compress%d(const uint32_t **input, uint8_t **output)
{
)", num_groups, num_bytes, groupings[num_values].elements_per_group * num_groups, num_values);

    for(int igroup = 0; igroup < num_groups; igroup++)
    {
        std::fprintf(file, "    uint64_t group%d = 0;", igroup);
        for(int ival = 0; ival < groupings[num_values].elements_per_group; ival++)
        {
            std::fprintf(file, R"(
    group%d *= %d;
    group%d += (*input)[%d];
)", igroup, num_values, igroup, ival);
        }
        int idx = igroup * groupings[num_values].bits_per_group;
        int byte_idx = idx / 8;
        int bit_idx = idx % 8;
        std::fprintf(file, R"(
    *((uint64_t *)((*output) + %d)) |= (group%d << %d);
    *input += %d;
)", byte_idx, igroup, bit_idx, groupings[num_values].elements_per_group);
    }
    std::fprintf(file, R"(    *output += %d;
}

)", num_bytes);
}

void WriteDecompressFunction(std::FILE *file, int num_values)
{
    int num_bits = LCM(groupings[num_values].bits_per_group, 8);
    int num_groups = num_bits / groupings[num_values].bits_per_group;
    int num_bytes = num_bits / 8;
    std::fprintf(file, R"(// Unpack %d bytes into %d values
void Ultrapack_Decompress%d(const uint8_t **input, uint32_t **output)
{
)", num_bytes, groupings[num_values].elements_per_group * num_groups, num_values);
    
    for(int igroup = 0; igroup < num_groups; igroup++)
    {
        int idx = igroup * groupings[num_values].bits_per_group;
        int byte_idx = idx / 8;
        int bit_idx = idx % 8;
        std::fprintf(file, "    uint64_t group%d = (*(uint64_t *)((*input) + %d)) >> %d;", igroup, byte_idx, bit_idx);
        for(int ival = 0; ival < groupings[num_values].elements_per_group; ival++)
        {
            std::fprintf(file, R"(
    (*output)[%d] = (uint32_t)(group%d %% %d);
    group%d /= %d;
)", ival, igroup, num_values, igroup, num_values);
        }
        std::fprintf(file, "    *output += %d;\n\n", groupings[num_values].elements_per_group);
    }
    std::fprintf(file, R"(
    *input += %d;
}

)", num_bytes);
}

void AddCompressFunctionToTable(FILE *file, int i)
{
    std::fprintf(file, "    Ultrapack_Compress%d,\n", i);
}

void AddDecompressFunctionToTable(FILE *file, int i)
{
    std::fprintf(file, "    Ultrapack_Decompress%d,\n", i);
}

int main()
{
    std::FILE *file = std::fopen("ultrapack.h", "w");
    std::fprintf(file,
R"(#pragma once
#include <cstdint>

struct UltrapackGrouping
{
    int elements_per_group;
    int bits_per_group;
};

UltrapackGrouping UltrapackGroupings[] =
{
    {  0,  0 }, )");
    for(int i = 2; i <= 256; i++)
        ComputeMinBitsPerValue(file, i);
    std::fprintf(file,
R"(};

int ElementsPerGroup(int num_distinct_values)
{
    return UltrapackGroupings[num_distinct_values - 1].elements_per_group;
}

int BitsPerGroup(int num_distinct_values)
{
    return UltrapackGroupings[num_distinct_values - 1].bits_per_group;
}

double BitsPerValue(int num_distinct_values)
{
    return static_cast<double>(BitsPerGroup(num_distinct_values)) / static_cast<double>(ElementsPerGroup(num_distinct_values));
}

)");
    for(int i = 2; i <= NumValuesToCompute; i++)
        WriteCompressFunction(file, i);

    std::fprintf(file, R"(
typedef void (*CompressFn)(const uint32_t **, uint8_t **);
CompressFn UltrapackCompress[] =
{
    0,
    0,
)");
    for(int i = 2; i <= NumValuesToCompute; i++)
        AddCompressFunctionToTable(file, i);
    std::fprintf(file, "};\n");

    for(int i = 2; i <= NumValuesToCompute; i++)
        WriteDecompressFunction(file, i);

    std::fprintf(file, R"(
typedef void (*DecompressFn)(const uint8_t **, uint32_t **);
DecompressFn UltrapackDecompress[] =
{
    0,
    0,
)");
    for(int i = 2; i <= NumValuesToCompute; i++)
        AddDecompressFunctionToTable(file, i);
    std::fprintf(file, "};\n");

    std::fclose(file);
    return 0;
}
