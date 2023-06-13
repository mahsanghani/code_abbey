#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#

# @lc code=start
import random
class RandomizedSet:

    def __init__(self):
        self.nummap = {}
        self.numlist = []

    def insert(self, val: int) -> bool:
        results = val not in self.nummap
        if results:
            self.nummap[val] = len(self.numlist)
            self.numlist.append(val)
        return results

    def remove(self, val: int) -> bool:
        results = val in self.nummap
        if results:
            idx = self.nummap[val]
            lastval = self.numlist[-1]
            self.numlist[idx] = lastval
            self.numlist.pop()
            self.nummap[lastval] = idx
            del self.nummap[val]
        return results

    def getRandom(self) -> int:
        return random.choice(self.numlist)

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end

