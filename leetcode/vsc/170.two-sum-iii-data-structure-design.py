#
# @lc app=leetcode id=170 lang=python3
#
# [170] Two Sum III - Data structure design
#

# @lc code=start
class TwoSum:

    def __init__(self):
        self.map = {}

    def add(self, number: int) -> None:
        self.map[number] = self.map.get(number,0)+1

    def find(self, value: int) -> bool:
        for number in self.map.keys():
            target = value - number
            if target in self.map:
                if target == number:
                    if self.map[target]>1:
                        return True
                    continue
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
            
# @lc code=end

