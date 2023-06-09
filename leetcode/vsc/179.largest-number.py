#
# @lc app=leetcode id=179 lang=python3
#
# [179] Largest Number
#

# @lc code=start
import collections
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        results = ""
        d=collections.defaultdict(list)
        
        for num in nums:
            d[str(num)[:1]].append(num)
        print(d)

        for k,v in sorted(list(d.items()), key=lambda x:x[0].lower(), reverse=True):
            for i,j in reversed(list(enumerate(v))):
                print(j)
                results+=str(j)

        return results
# @lc code=end

