#!/usr/bin/python3

import os, sys, subprocess
import argparse

#def  main(argv):
parser = argparse.ArgumentParser(description='Run communication benchamrks')
parser.add_argument('-test', meta_var='tests_to_run', type=str, help = 'The tests to run')
args = parser.parse_args()

file_to_test = args.tests_to_run

print (file_to_test)

#if __name__ == "__main__":
#   main(sys.argv[:])