class Solution:
    def minSwaps(self, s: str) -> int:
        stack=0
        
        for c in s:
            if c=="[":
                stack+=1
            if c=="]":
                if stack>0:
                    stack-=1

        return (stack+1)//2