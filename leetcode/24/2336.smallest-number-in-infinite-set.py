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
        if len(self.small)>1:
            self.small = self.small[1:]
        return temp

    def addBack(self, num: int) -> None:
        if num not in self.small:
            if num<self.small[0]:
                self.small.insert(0,num)
            else:
                # idx = self.binary(num)
                self.small.insert(self.binary(num),num)
    
    def binary(self, num):
        left, right = 0,len(self.small)-1

        while left<=right:
            mid = left+(right-left)//2
            if self.small[mid]==num:
                return mid
            elif self.small[mid]<num:
                left=mid+1
            else:
                right=mid-1
        return left

# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
# @lc code=end

