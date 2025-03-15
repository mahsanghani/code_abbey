class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        missing = 1
        
        while True:
            flag = True
            for num in nums:
                if missing == num:
                    flag = False
                    break

            if flag:
                return missing
            
            missing += 1
