class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n = len(neededTime)
        i = 0
        res = 0
        
        while i<n:
            j=i
            maxi=0
            curr=0

            while j<n and colors[j]==colors[i]:
                maxi = max(maxi,neededTime[j])
                curr += neededTime[j]
                j+=1

            res += curr - maxi
            i = j

        return res
    