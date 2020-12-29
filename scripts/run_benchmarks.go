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
	
	cmdOutput, err := exec.Command(argsWithoutProg[0]).Output()

	if err != nil {
		log.Fatal(err)
	}
	
	fmt.Printf("%s", cmdOutput)

}