#!/bin/python3

import math
import os
import random
import re
import sys

def activityNotifications(expenditure, d):
    counts = [0]*201
    notifications = 0
    
    for i in range(d):
        counts[expenditure[i]] += 1
        
    for j in range(d, len(expenditure)):
        median = getMedian(counts, d)
        
        if expenditure[j] >= 2*median:
            notifications += 1
            
        counts[expenditure[j-d]] -= 1
        counts[expenditure[j]] += 1
        
    return notifications
    
def getMedian(counts, d):
    if d%2 == 1:
        mid = (d+1)//2
        count = 0
        
        for i in range(201):
            count += counts[i]
            if count >= mid:
                return i
                
    else:
        left = d//2
        right = left + 1
        count = 0
        l = r = 0
        
        for j in range(201):
            count += counts[j]
            
            if count >= left and l==0:
                l = j
            if count >= right:
                r = j
                break
                
        return (l+r)/2
        
    return 0

if __name__ == '__main__':
    nd = input().split()
    n = int(nd[0])
    d = int(nd[1])
    expenditure = list(map(int, input().rstrip().split()))
    result = activityNotifications(expenditure, d)
    print(str(result))
    