#g++ codegen.cpp -o codegen -O2
#./codegen
#g++ ultrapack_bench.cpp -o ultrapack_bench -O2 -std=c++20
#./ultrapack_bench
g++ bitpack_codegen.cpp -o bitpack_codegen -O2
./bitpack_codegen
g++ bitpack_bench.cpp -o bitpack_bench -O2 -std=c++20
./bitpack_bench
