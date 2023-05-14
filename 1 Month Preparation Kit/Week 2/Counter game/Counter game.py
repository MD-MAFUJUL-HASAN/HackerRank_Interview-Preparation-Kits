#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'counterGame' function below.
#
# The function is expected to return a STRING.
# The function accepts LONG_INTEGER n as parameter.
#


def counterGame(n):
    # Write your code here
    num = n
    turns = 0
    while num > 1:
        ln = math.log(num, 2)
        if int(ln) == ln:
            return "Louise" if (ln + turns) % 2 else "Richard"
        else:
            num -= 2**int(ln)
        turns += 1
        print(num)
    return "Louise" if turns % 2 else "Richard"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
