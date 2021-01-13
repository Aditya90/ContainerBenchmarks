#include "Benchmarks/ExampleBenchmark.h"
#include "Benchmarks/CommunicationData.h"
#include "Benchmarks/CommunicationDataConcept.h"
#include "Benchmarks/DataTypes/CommsProtocol.pb.h"

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

static void ConceptBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(ConceptTests::doSomething<CommunicationData>(CommunicationData{}));
  }
}

static void ProtobufBenchmark(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets benchmark::DoNotOptimize timed
    benchmark::DoNotOptimize(NetworkMessage());
  }
}

// Register the function as a benchmark
BENCHMARK(SampleBenchmark);
BENCHMARK(ConceptBenchmark);
BENCHMARK(ProtobufBenchmark);

BENCHMARK_TEMPLATE(SampleVectorBenchmark, CommunicationData)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
BENCHMARK_TEMPLATE(SampleVectorBenchmark, int)->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);
