#
# @lc app=leetcode id=1151 lang=python3
#
# [1151] Minimum Swaps to Group All 1's Together
#
# @lc code=start
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        left = 0
        right = 0
        sub = 0
        win = 0

        while right<len(data):
            win+=data[right]
            right+=1

            if right-left>ones:
                win-=data[left]
                left+=1
            
            sub = max(sub,win)
        return ones-sub
# @lc code=end

