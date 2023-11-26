#
# @lc app=leetcode id=1365 lang=python3
#
# [1365] How Many Numbers Are Smaller Than the Current Number
#

# @lc code=start
from collections import Counter
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        # dictionary
        # sort keys
        # count values
        results = []
        counts = Counter(nums)
        sorted_counts = dict(sorted(counts.items()))
        for num in nums:
            if num in sorted_counts:
                results.append(sum(v for k,v in sorted_counts.items() if k<num))

        return results
# @lc code=end

