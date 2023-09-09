#
# @lc app=leetcode id=1286 lang=python3
#
# [1286] Iterator for Combination
#

# @lc code=start
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.n = n = len(characters)
        self.k = k = combinationLength
        self.chars = characters

        self.b = (1<<n) - (1<<n-k)

    def next(self) -> str:
        current = [self.chars[j] for j in range(self.n) if self.b & (1<<self.n-j-1)]
        self.b -= 1
        while self.b>0 and bin(self.b).count('1') != self.k:
            self.b -= 1

        return ''.join(current)

    def hasNext(self) -> bool:
        return self.b > 0


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

