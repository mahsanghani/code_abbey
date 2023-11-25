#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#

# @lc code=start
class Solution:
    def generate(self, n: int) -> List[List[int]]:
        if n==0:
            return []
        elif n==1:
            return [[1]]
        else:
            new = [1]
            res = self.generate(n-1)
            last = res[-1]
            for i in range(len(last)-1):
                new.append(last[i]+last[i+1])
            new+=[1]
            res.append(new)
        return res

# @lc code=end

