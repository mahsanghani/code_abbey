#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        rightMax = []
        results = []
        right = -1

        for i in range(len(nums2)-1,-1,-1):
            # rightMax.insert(0,right)
            new = max(nums2[i],right)
            rightMax.insert(0,right)
            right = new

        print(rightMax)
        for num in nums1:
            results.append(rightMax[nums2.index(num)])

        return results

# @lc code=end

