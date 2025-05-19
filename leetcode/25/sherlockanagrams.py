#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s):
    """
    Find all unordered anagrammatic pairs of substrings in the given string.

    Args:
        s (str): Input string

    Returns:
        int: Number of unordered anagrammatic pairs
    """
    # Dictionary to store sorted substrings and their counts
    substring_dict = {}

    # Generate all possible substrings and count anagrams
    n = len(s)
    for i in range(n):
        for j in range(i + 1, n + 1):
            # Get substring and sort characters (anagrams will have the same sorted string)
            substr = ''.join(sorted(s[i:j]))

            # Count occurrences of this sorted substring
            if substr in substring_dict:
                substring_dict[substr] += 1
            else:
                substring_dict[substr] = 1

    # Calculate number of anagrammatic pairs
    total_pairs = 0
    for count in substring_dict.values():
        # If we have n occurrences, we can form n*(n-1)/2 pairs
        total_pairs += (count * (count - 1)) // 2

    return total_pairs


# Function to process input and output
if __name__ == '__main__':
    q = int(input().strip())  # Number of test cases

    for q_itr in range(q):
        s = input()  # Input string
        result = sherlockAndAnagrams(s)
        print(result)  # Print the result
