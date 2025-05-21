#!/bin/python3

import math
import os
import random
import re
import sys

def luckBalance(k, contests):
    imp = [i for i,j in contests if j==1]
    unimp = [i for i,j in contests if j==0]
    
    imp.sort(reverse=True)
    
    return sum(imp[:k]) - sum(imp[k:]) + sum(unimp)
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
