g++ codegen.cpp -o codegen -O2
./codegen
g++ ultrapack_bench.cpp -o ultrapack_bench -O2 -std=c++20
./ultrapack_bench
