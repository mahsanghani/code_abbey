class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        left=0
        right=0
        flips=0
        minflips=10**9

        for right in range(k,len(blocks)+1):
            minflips = min(minflips,blocks[left:right].count("W"))
            left+=1

        return minflips
