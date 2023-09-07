#
# @lc app=leetcode id=362 lang=python3
#
# [362] Design Browser History
#

# @lc code=start
class HitCounter:

    def __init__(self):
        self.hits = []

    def hit(self, timestamp: int) -> None:
        self.hits.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        left = 0
        right = len(self.hits) - 1
        target = timestamp - 300
        while left <= right:
            mid = (left + right) // 2
            if self.hits[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return len(self.hits) - left


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
# @lc code=end

