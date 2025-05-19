#!/bin/python3

import math
import os
import random
import re
import sys
import collections
from collections import Counter

def isValid(s):
    d = Counter(s)
    freq = Counter(d.values())
    
    if len(freq)==1:
        return "YES"
        
    if len(freq)>2:
        return "NO"
        
    freqs = list(freq.keys())
    
    if abs(freqs[0] - freqs[1])==1 and (freq[freqs[0]]==1 or freq[freqs[1]]==1):
        return "YES"
        
    if 1 in freqs and freq[1]==1:
        return "YES"
        
    return "NO"

if __name__ == '__main__':
    s = "aabbccddeefghi"
    result = isValid(s)
    print(result)
    