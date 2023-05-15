#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'waiter' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY number
#  2. INTEGER q
#

def waiter(number, q):
    # Write your code here
    res, prime = [], [2]
    for i in range(q):
        nextPr = prime[-1]
        if i > 0:
            notPrime = True
            while notPrime:
                nextPr += 1
                for p in prime:
                    if nextPr%p == 0:
                        break
                    if p == prime[-1]:
                        prime.append(nextPr)
                        notPrime = False
        a = []
        for n in number:
            if n%nextPr == 0:
                res.append(n)
            else:
                a.insert(0, n)
        number = a
    while number:
        res.append(number.pop())  
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    number = list(map(int, input().rstrip().split()))

    result = waiter(number, q)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
