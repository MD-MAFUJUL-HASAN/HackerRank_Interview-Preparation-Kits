#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#


def isValid(s):
    # Write your code here
    d = Counter(s.lower())
    counts = list(d.values())
    if len(set(counts)) == 1:
        return 'YES'
    counts.sort()
    if counts[0] == 1 and len(set(counts[1:])) == 1:
        return 'YES'
    counts[-1] -= 1
    if len(set(counts)) == 1:
        return 'YES'
    return 'NO'


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
