class Solution:
    def minSwaps(self, s: str) -> int:
        op=0
        cl=0
        diff=0

        for c in s:
            if c=="[":
                op+=1
            if c=="]":
                cl+=1
                diff=max(diff,cl-op)

        return (diff+1)//2