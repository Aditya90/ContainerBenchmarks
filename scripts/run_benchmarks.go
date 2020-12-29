package main

import (
	"fmt"
	"os"
	"log"
	"os/exec"	
)

func main() {

	// Print Go Version
	// cmdOutput, err := os.exec.Command("go", "version").Output()

	argsWithoutProg := os.Args[1:]

	fmt.Printf("%s", argsWithoutProg)
	
	_, err := exec.Command(argsWithoutProg[0], "--benchmark_format=json", "--benchmark_out=testBenchmarks.json").Output()
	
	if err != nil {
		log.Fatal(err)
	}

	// Compare the new benchmark v/s the reference
	compareOutput, compareErr := exec.Command("python3", "./benchmark/tools/compare.py", "benchmarks", "referenceBenchmarks.json", "testBenchmarks.json").Output();

	if compareErr != nil {
		log.Fatal(compareErr)
	}
	fmt.Printf("%s", compareOutput)
	
}