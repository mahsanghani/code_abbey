#
# @lc app=leetcode id=2610 lang=python3
#
# [2610] Convert an Array Into a 2D Array With Conditions
#

# @lc code=start
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        rows = [[]]
        freq = [0]*(len(nums)+1)

        for num in nums:
            if freq[num] >= len(rows):
                rows.append([])
            
            rows[freq[num]].append(num)
            freq[num]+=1
        
        return rows
# @lc code=end

