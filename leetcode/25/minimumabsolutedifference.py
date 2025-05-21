#!/bin/python3

import math
import os
import random
import re
import sys

def minimumAbsoluteDifference(arr):
    diff = 9e7
    arr.sort()
    
    for i in range(1,len(arr)):
        diff = min(diff,abs(arr[i]-arr[i-1]))
        
    return diff
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = minimumAbsoluteDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
