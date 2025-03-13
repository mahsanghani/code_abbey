class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        res=[]
        grp=[]
        maxnum=max(nums)
        count=[0]*(maxnum+1)
        
        for num in nums:
            count[num] += 1
            
        for num in range(maxnum+1):
            while count[num] > 0:
                grp.append(num)
                count[num]-=1

                if len(grp)==3:
                    if grp[2]-grp[0]>k:
                        return []
                    res.append(grp)
                    grp = []

        return res
