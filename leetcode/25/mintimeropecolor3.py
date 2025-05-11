class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        res = 0
        maxi = 0

        for i in range(len(colors)):
            if i and colors[i] != colors[i-1]:
                maxi = 0
            res += min(maxi, neededTime[i])
            maxi = max(maxi, neededTime[i])

        return res
    