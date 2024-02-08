#
# @lc app=leetcode id=832 lang=python3
#
# [832] Flipping an Image
#

# @lc code=start
class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        results = []
        for i,j in enumerate(image):
            results.append(j[::-1])
            results[i] = [0 if x==1 else 1 for x in results[i]]
        return results    
# @lc code=end

