#
# @lc app=leetcode id=1286 lang=python3
#
# [1286] Iterator for Combination
#

# @lc code=start
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.combinations = []
        n,k = len(characters), combinationLength
        
        for bitmask in range(1<<n):
            if bin(bitmask).count('1') == k:
                current= [characters[j] for j in range(n) if bitmask & (1<<n-j-1)]
                self.combinations.append(''.join(current))

    def next(self) -> str:
        return self.combinations.pop()

    def hasNext(self) -> bool:
        return self.combinations


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

