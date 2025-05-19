#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    # Create counting array for tracking frequencies
    # Problem states expenditure values can be 0-200
    count_array = [0] * 201
    notifications = 0
    
    # Initialize counting array with first d elements
    for i in range(d):
        count_array[expenditure[i]] += 1
    
    # Process the rest of the array
    for i in range(d, len(expenditure)):
        # Find median
        median = getMedian(count_array, d)
        
        # Check if notification is needed
        if expenditure[i] >= 2 * median:
            notifications += 1
        
        # Update sliding window
        count_array[expenditure[i-d]] -= 1  # Remove oldest element
        count_array[expenditure[i]] += 1    # Add newest element
    
    return notifications

def getMedian(count_array, d):
    # If d is odd, find the middle element
    if d % 2 == 1:
        middle = (d + 1) // 2
        count_sum = 0
        for i in range(201):
            count_sum += count_array[i]
            if count_sum >= middle:
                return i
    # If d is even, find the average of the two middle elements
    else:
        first_middle = d // 2
        second_middle = first_middle + 1
        count_sum = 0
        first_value = second_value = 0
        
        for i in range(201):
            count_sum += count_array[i]
            
            if count_sum >= first_middle and first_value == 0:
                first_value = i
            
            if count_sum >= second_middle:
                second_value = i
                break
                
        return (first_value + second_value) / 2
    
    # This should never be reached if input is valid
    return 0

# Sample test case
if __name__ == '__main__':
    # This part handles the input/output as per HackerRank specifications
    nd = input().split()
    n = int(nd[0])
    d = int(nd[1])
    expenditure = list(map(int, input().rstrip().split()))
    result = activityNotifications(expenditure, d)
    print(str(result))
    