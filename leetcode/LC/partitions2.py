class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if sum(nums)%k:
            return False
        nums.sort(reverse=True)
        target = sum(nums)/k
        used = [False]*len(nums)
        
        def dfs(i,k,sub):
            if k==0:
                return True

            if sub==0:
                return dfs(0,k-1,target)
            
            for j in range(i,len(nums)):
                if j>0 and not used[j-1] and nums[j]==nums[j-1]:
                    continue
                    
                if used[j] and sub-nums[j]<0:
                    continue
                
                used[j] = True
                
                if dfs(j+1,k,sub-nums[j]):
                    return True
                used[j] = False
            return False
        return dfs(0,k,target)
