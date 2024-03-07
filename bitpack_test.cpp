#include <random>
#include <vector>

#include "bitpack.h"

constexpr int NumValues = 1024;
constexpr int Padding = 64;

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
void Test()
{
    Test<NumDistinct - 1>();
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<> dist(0, NumDistinct - 1);

    std::vector<uint32_t> vals(NumValues + Padding);
    std::vector<uint32_t> decompressed(NumValues + Padding);
    for(auto &a : vals)
        a = dist(e);
    std::vector<uint8_t> compressed(NumValues * sizeof(uint32_t) + Padding);
    Compress<NumDistinct>(NumValues, vals.data(), compressed.data());
    Decompress<NumDistinct>(NumValues, compressed.data(), decompressed.data());
    for(size_t i = 0; i < NumValues; i++)
    {
        if(vals[i] != decompressed[i])
        {
            printf("Bitpack Test %d failed at index %d (%d != %d)\n", NumDistinct, i, vals[i], decompressed[i]);
            return;
        }
    }
    printf("Bitpack Test %d succeeded!\n", NumDistinct);
}

template <>
void Test<1>()
{
    return;
}

int main()
{
    Test<256>();
    return 0;
}
