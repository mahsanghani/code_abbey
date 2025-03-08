class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        pre = 0
        mod = {0:-1}

        if len(nums)<2:
            return False

        for i in range(len(nums)):
            pre = (pre+nums[i])%k
            
            if pre in mod:
                if i-mod[pre]>1:
                    return True
            if pre not in mod:
                mod[pre] = i

        return False