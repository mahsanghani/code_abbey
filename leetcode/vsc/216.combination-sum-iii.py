#
# @lc app=leetcode id=216 lang=python3
#
# [216] Combination Sum III
#

# @lc code=start
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        results = []
        numbers = list(range(1,10))
        
        def calculate(k,n,path,idx,numbers):
            if k<0 or n<0:
                return
            
            if k==0 and n==0:
                results.append(path[:])
                return
            
            for i in range(idx,len(numbers)):
                path.append(numbers[i])
                calculate(k-1,n-numbers[i],path,i+1,numbers)
                path.pop()

        calculate(k,n,[],0,numbers)

        return results
# @lc code=end

