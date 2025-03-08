class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        pre = 0
        mod = {0:-1}
        
        for i in range(len(nums)):
            pre = (pre+nums[i])%k

            if pre in mod:
                if i-mod[pre]>1:
                    return True
            else:
                mod[pre]=i

        return False