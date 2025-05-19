#!/bin/python3

import math
import os
import random
import re
import sys

def countInversions(arr):
    def mergeCount(arr, temp, left, mid, right):
        count = 0
        
        i = left
        j = mid+1
        k = left
        
        while i<=mid and j<=right:
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                i += 1
            else:
                temp[k] = arr[j]
                count += (mid-i+1)
                j += 1
            k += 1
            
        while i<=mid:
            temp[k] = arr[i]
            i += 1
            k += 1
            
        while j<=right:
            temp[k] = arr[j]
            j += 1
            k += 1
            
        for i in range(left, right + 1):
            arr[i] = temp[i]
            
        return count
        
    def mergeSortCount(arr, temp, left, right):
        count = 0
        
        if left < right:
            mid = (left + right) // 2
            count += mergeSortCount(arr, temp, left, mid)
            count += mergeSortCount(arr, temp, mid+1, right)
            count += mergeCount(arr, temp, left, mid, right)
            
        return count
        
    n = len(arr)
    temp = [0]*n
    return mergeSortCount(arr,temp,0,n-1)

# Example usage:
test_arr = [2, 1, 3, 1, 2]
print(countInversions(test_arr))  
# # Should output 5

