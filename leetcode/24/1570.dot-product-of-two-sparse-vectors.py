#
# @lc app=leetcode id=1570 lang=python3
#
# [1570] Dot Product of Two Sparse Vectors
#
# @lc code=start
class SparseVector:
    def __init__(self, nums: List[int]):
        self.dict = {}
        for i,j in enumerate(nums):
            if j!=0:
                self.dict[i]=j

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        results = 0

        for i in set(self.dict.keys()) & set(vec.dict.keys()):
            results += self.dict[i] * vec.dict[i]

        return results

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
# @lc code=end

