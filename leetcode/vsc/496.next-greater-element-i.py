#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        idx = {n:i for i,n in enumerate(nums1)}
        res = [-1]*len(nums1)
        stack = []

        for i in range(len(nums2)):
            curr = nums2[i]
            while stack and curr>stack[-1]:
                val = stack.pop()
                id = idx[val]
                res[id] = curr
            if curr in idx:
                stack.append(curr)
        return res

# @lc code=end

