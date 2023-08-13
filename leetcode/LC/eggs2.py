class Solution:
    def twoEggDrop(self, n: int) -> int:
        return ceil((-1.0 + sqrt(1 + 8 * n)) / 2.0)
