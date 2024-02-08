#
# @lc app=leetcode id=832 lang=python3
#
# [832] Flipping an Image
#

# @lc code=start
class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for i,j in enumerate(image):
            image[i] = j[::-1]
            image[i] = [0 if x==1 else 1 for x in image[i]]
        return image
# @lc code=end

