#!/bin/python3

import math
import os
import random
import re
import sys

#  1. INTEGER k
#  2. INTEGER_ARRAY A
#  3. INTEGER_ARRAY B
#

n = int(input())
for _ in range(n):
    __, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())), reverse=True)
    if all([a[i] + b[i] >= k for i in range(len(a))]):
        print('YES')
    else:
        print('NO')
