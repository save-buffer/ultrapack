g++ codegen.cpp -o codegen -O2
./codegen
g++ bitpack_codegen.cpp -o bitpack_codegen -O2
./bitpack_codegen
g++ ultrapack_test.cpp -o ultrapack_test -O2 -ggdb -std=c++20
./ultrapack_test
g++ bitpack_test.cpp -o bitpack_test -O2 -ggdb -std=c++20
./bitpack_test

g++ ultrapack_bench.cpp -o ultrapack_bench -O2 -ggdb -std=c++20
./ultrapack_bench
g++ bitpack_bench.cpp -o bitpack_bench -O2 -std=c++20
./bitpack_bench
