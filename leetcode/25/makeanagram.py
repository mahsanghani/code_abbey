#!/bin/python3

import math
import os
import random
import re
import sys
import collections
from collections import Counter

def makeAnagram(a, b):
    res=0
    # a = a.split()
    # b = b.split()
    a_d = Counter(a)
    b_d = Counter(b)
    
    for k,v in a_d.items():
        if k in b_d:
            res += max(0, v - b_d[k])
        else:
            res += v
            
    for k,v in b_d.items():
        if k in a_d:
            res += max(0, v - a_d[k])
        else:
            res += v
            
    return res

# Example usage
if __name__ == "__main__":
    a = "cde"
    b = "abc"
    print(makeAnagram(a, b))  # Should print 8
