#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i,l = 0,len(set(nums))
        newset = set()

        while i<l:
            if nums[i] in newset:
                nums.pop(i)
                nums.append('_')
            else:
                newset.add(nums[i])
                i+=1
        return len(newset)
# @lc code=end

