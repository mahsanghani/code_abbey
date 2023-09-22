#
# @lc app=leetcode id=946 lang=python3
#
# [946] Validate Stack Sequences
#

# @lc code=start
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i=0
        stack=[]
        for num in pushed:
            stack.append(num)
            while stack and i<len(popped) and stack[-1]==popped[i]:
                i+=1 
                stack.pop()
        return not stack

# @lc code=end

