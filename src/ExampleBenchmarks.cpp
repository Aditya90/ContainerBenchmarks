#include "ExampleBenchmark.h"
#include "CodeToTest.h"

#include <benchmark/benchmark.h>

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    functionToProfile();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);