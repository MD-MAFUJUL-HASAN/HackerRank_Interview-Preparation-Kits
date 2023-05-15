#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'truckTour' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
#

def truckTour(petrolpumps):
    # Write your code here
    N = len(petrolpumps)

    for i in range(N):
        j = 0
        tank_cap = 0
        valid_tour = True

        while j < N:
            liters, dist = petrolpumps[(j + i) % N]
            tank_cap += liters - dist
            j += 1

            if tank_cap < 0:
                valid_tour = False
                break

        if valid_tour:
            return i
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    petrolpumps = []

    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)

    fptr.write(str(result) + '\n')

    fptr.close()
