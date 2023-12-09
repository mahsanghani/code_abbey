#
# @lc app=leetcode id=2161 lang=python3
#
# [2161] Partition Array According to Given Pivot
#

# @lc code=start
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = []
        same = []
        more = []

        for num in nums:
            if num > pivot:
                more.append(num)
            elif num < pivot:
                less.append(num)
            elif num == pivot:
                same.append(num)

        return less + same + more
# @lc code=end

