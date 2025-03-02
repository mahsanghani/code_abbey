from collections import deque

class Solution:
    def minSwaps(self, s: str) -> int:
        stack=deque()
        diff=0

        for c in s:
            if c=="[":
                stack.append(c)
            if c=="]":
                if stack:
                    stack.pop()
                else:
                    diff+=1

        return (diff+1)//2