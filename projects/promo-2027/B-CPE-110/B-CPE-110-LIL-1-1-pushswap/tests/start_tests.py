#!/usr/bin/python3

# create a program that will run a number of tests given as command line arguments

#./start_tests.py [number of tests] [number of numbers in each test]

# for i in range(number of tests):
#   run the push_swap program with a list of random numbers
#   store the output of the program in a out file
#   run the checker program with the same list of random numbers and the output of the push_swap program
#   if checker returns OK, print OK, else print KO

import sys
import random
import os

def main():
    if len(sys.argv) != 5:
        print("Usage: ./start_tests.py [number of tests] [number of numbers in each test] [min number] [max number]")
        exit(1)
    num_tests = int(sys.argv[1])
    num_nums = int(sys.argv[2])
    a = int(sys.argv[3])
    b = int(sys.argv[4])
    for i in range(num_tests):
        nums = []
        for j in range(num_nums):
            nums.append(str(random.randint(a, b)))
        nums = " ".join(nums)
        file = open("nums", "w")
        file.write(nums)
        file.close()
        os.system("./push_swap " + nums + " > out")
        os.system("./checker.py " + nums + " < out")

if __name__ == "__main__":
    main()