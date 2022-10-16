class Solution:
    def twoEggDrop(self, n: int) -> int:
        c = 0
        it = n
        while it > 0:
            c += 1
            it -= c
        return c
