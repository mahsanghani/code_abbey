#
# @lc app=leetcode id=338 lang=python3
#
# [338] Counting Bits
#
# @lc code=start
class Solution:
    def countBits(self, n: int) -> List[int]:
        count = 0
        results = []
        for i in range(n+1):
            for c in str(bin(i)):
                if c=="1":
                    count+=1
            results.append(count)
            count = 0
        return results
# @lc code=end

