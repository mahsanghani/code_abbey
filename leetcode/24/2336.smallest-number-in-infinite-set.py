#
# @lc app=leetcode id=2336 lang=python3
#
# [2336] Smallest Number in Infinite Set
#
# @lc code=start
class SmallestInfiniteSet:
    def __init__(self):
        self.small = list(range(1,1001))

    def popSmallest(self) -> int:
        temp = self.small[0]
        self.small = self.small[1:]
        return temp

    def addBack(self, num: int) -> None:
        if num not in self.small:
            self.small.insert(num-1,num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
# @lc code=end

