#
# @lc app=leetcode id=1286 lang=python3
#
# [1286] Iterator for Combination
#
# @lc code=start
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.chars = characters
        self.length = combinationLength
        self.results = []
        self.backtrack(0,[])

    def next(self) -> str:
        item = self.results[0]
        self.results = self.results[:-1]
        return item

    def hasNext(self) -> bool:
        return len(self.results)>0


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

