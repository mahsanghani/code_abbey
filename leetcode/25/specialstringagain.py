#!/bin/python3

import math
import os
import random
import re
import sys
import collections
from collections import Counter

def substrCount(n, s):
    count = n
    groups = []
    char = s[0]
    curr = 1
    
    for i in range(1,n):
        if s[i] == char:
            curr += 1
        else:
            groups.append((char,curr))
            char = s[i]
            curr = 1
            
    groups.append((char,curr))
    
    for k,v in groups:
        if v>1:
            count += (v*(v-1))//2
            
    for i in range(1,len(groups)-1):
        if groups[i-1][0] == groups[i+1][0] and groups[i][1] == 1:
            count += min(groups[i-1][1], groups[i+1][1])
            
    return count
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    s = input()
    result = substrCount(n, s)
    fptr.write(str(result) + '\n')
    fptr.close()
