#!/bin/python3

import math
import os
import random
import re
import sys

def maxMin(k, arr):
    unfairness = 9e7
    arr.sort()
    
    for i in range(len(arr)-k+1):
        curr = arr[i+k-1]-arr[i]
        unfairness = min(unfairness, curr)

    return unfairness

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    k = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = maxMin(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
