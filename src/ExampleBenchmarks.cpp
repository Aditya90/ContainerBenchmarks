#include "ExampleBenchmark.h"
#include "CodeToTest.h"

#include <benchmark/benchmark.h>

static void SampleBenchmark(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets benchmark::DoNotOptimizetimed
    benchmark::DoNotOptimize(functionToProfile);
  }
}

// Register the function as a benchmark
BENCHMARK(SampleBenchmark);