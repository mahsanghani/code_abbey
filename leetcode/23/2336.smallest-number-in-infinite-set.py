#
# @lc app=leetcode id=2336 lang=python3
#
# [2336] Smallest Number in Infinite Set
#

# @lc code=start
class SmallestInfiniteSet:

    def __init__(self):
        self.current = 1
        self.set = set()

    def popSmallest(self) -> int:
        if self.set:
            res = min(self.set)
            self.set.remove(res)
            return res
        else:
            self.current += 1
            return self.current - 1

    def addBack(self, num: int) -> None:
        if self.current > num:
            self.set.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
# @lc code=end

