#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_power_mat_mat(benchmark::State &state) {
    Matrix mat1 = read_csv("./datasets/boston/boston.csv");
    Matrix mat2 = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());
    sliced_mat1.to_double();
    sliced_mat2.to_double();
    for (auto _ : state)
        matrix.power(sliced_mat1, sliced_mat2);
}
BENCHMARK(BM_power_mat_mat);

static void BM_power_mat_sca(benchmark::State &state) {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.power(sliced_mat, 2);
}
BENCHMARK(BM_power_mat_sca);

BENCHMARK_MAIN();