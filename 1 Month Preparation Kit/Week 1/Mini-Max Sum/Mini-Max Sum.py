#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#


def miniMaxSum(arr):
    arr.sort()
    sum1 = sum(arr[i] for i in range(0, len(arr)-1))
    sum2 = sum(arr[j] for j in range(1, len(arr)))
    print(sum1, sum2)


if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
