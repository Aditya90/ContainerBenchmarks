#include "ExampleBenchmark.h"
#include "CodeToTest.h"

#include <benchmark/benchmark.h>

static void SampleBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(CommunicationData{});
  }
}

static void SampleVectorBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(std::vector<CommunicationData>{state.range(0)});
  }
  state.SetComplexityN(state.range(0));
}

// Register the function as a benchmark
BENCHMARK(SampleBenchmark);
BENCHMARK(SampleVectorBenchmark)->DenseRange(0, 1024, 128)->Complexity();
