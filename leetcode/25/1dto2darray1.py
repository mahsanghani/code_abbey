class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        res=[]

        while len(nums)>0:
            row = list(set(nums))
            res.append(row)

            for num in row:
                nums.remove(num)
                
        return res
