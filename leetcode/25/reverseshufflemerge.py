#!/bin/python3

import math
import os
import random
import re
import sys
import collections
from collections import Counter

def reverseShuffleMerge(s):
    results = []
    stashed = Counter(s)
    required = {k:v//2 for k,v in stashed.items()}
    
    for c in reversed(s):
        stashed[c] -= 1
        if required[c] <= 0:
            continue
        
        while results:
            last_c = results[-1]
            if (c<last_c) and (stashed[last_c] >= required[last_c]+1):
                results.pop()
                required[last_c] += 1
            else:
                break
                
        results.append(c)
        required[c] -= 1
        
    return "".join(results)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = reverseShuffleMerge(s)

    fptr.write(result + '\n')

    fptr.close()
