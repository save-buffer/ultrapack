#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <random>
#include <string>
#include <vector>

#include "bitpack.h"

constexpr int NumValues = 1024 * 1024;
constexpr int Padding = 64;

std::ofstream benchmark_compress_csv("benchmark_compress_bitpack.csv", std::ios::out | std::ios::trunc);
std::ofstream benchmark_decompress_csv("benchmark_decompress_bitpack.csv", std::ios::out | std::ios::trunc);

template <int NumDistinct>
void Compress(uint32_t num_values, const uint32_t *input, uint8_t *output)
{
    auto compress_fn = BitpackCompress[NumDistinct];
    const uint32_t *end = input + num_values;
    while(input < end)
        compress_fn(&input, &output);
}

template <int NumDistinct>
void Decompress(uint32_t num_values, const uint8_t *input, uint32_t *output)
{
    auto decompress_fn = BitpackDecompress[NumDistinct];
    const uint32_t *end = output + num_values;
    while(output < end)
        decompress_fn(&input, &output);
}

template <int NumDistinct>
void BenchmarkBitpack()
{
    BenchmarkBitpack<NumDistinct - 1>();
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<> dist(0, NumDistinct - 1);

    std::vector<uint32_t> vals(NumValues + Padding);
    for(auto &a : vals)
        a = dist(e);

    std::vector<uint8_t> compressed(NumValues * sizeof(uint32_t) + Padding);
    ankerl::nanobench::Bench().batch(NumValues).run("Compress" + std::to_string(NumDistinct), [&]()
    {
        Compress<NumDistinct>(NumValues, vals.data(), compressed.data());
    }).render(std::to_string(NumDistinct) + ", {{batch}}, {{average(cpucycles)}}, {{average(instructions)}}\n", benchmark_compress_csv);

    ankerl::nanobench::Bench().batch(NumValues).run("Decompress" + std::to_string(NumDistinct), [&]()
    {
        Decompress<NumDistinct>(NumValues, compressed.data(), vals.data());
    }).render(std::to_string(NumDistinct) + ", {{batch}}, {{average(cpucycles)}}, {{average(instructions)}}\n", benchmark_decompress_csv);

}

template <>
void BenchmarkBitpack<1>()
{
    return;
}

int main()
{
    BenchmarkBitpack<256>();
    return 0;
}
