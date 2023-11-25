#
# @lc app=leetcode id=1470 lang=python3
#
# [1470] Shuffle the Array
#

# @lc code=start
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        a = nums[:n]
        b = nums[n:]
        c = []
        for i in range(n):
            c.append(a[i])
            c.append(b[i])
        return c
# @lc code=end

