#include "ExampleBenchmark.h"
#include "CommunicationData.h"
#include "DataStructures/CustomDataStructures.h"

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

template <class TypeToTest>
static void SampleVectorBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(std::vector<TypeToTest>{state.range(0)});
  }
  state.SetComplexityN(state.range(0));
}

template <class TypeToTest>
static void QueueBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(Queue<TypeToTest>{state.range(0)});
  }
  state.SetComplexityN(state.range(0));
}

// Register the function as a benchmark
BENCHMARK(SampleBenchmark);

BENCHMARK_TEMPLATE(SampleVectorBenchmark, CommunicationData)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
BENCHMARK_TEMPLATE(SampleVectorBenchmark, int)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
BENCHMARK_TEMPLATE(QueueBenchmark, CommunicationData)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
BENCHMARK_TEMPLATE(QueueBenchmark, int)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
