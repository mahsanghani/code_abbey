#
# @lc app=leetcode id=1534 lang=python3
#
# [1534] Count Good Triplets
#

# @lc code=start
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        results = []
        for i in range(len(arr)-2):
            for j in range(1,len(arr)-1):
                for k in range(2,len(arr)):
                    if i<j<k \
                    and abs(arr[i]-arr[j])<=a \
                    and abs(arr[j]-arr[k])<=b \
                    and abs(arr[i]-arr[k])<=c:
                        results.append((arr[i],arr[j],arr[k]))
                        continue
        # print(results)
        return len(results)
# @lc code=end

