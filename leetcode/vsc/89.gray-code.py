#
# @lc app=leetcode id=89 lang=python3
#
# [89] Gray Code
#

# @lc code=start
class Solution:
    def grayCode(self, n: int) -> List[int]:
        def calculate(n):
            if n==1:
                return ["0","1"]
            temp = calculate(n-1)
            results = []
            
            for i in range(len(temp)):
                results.append("0" + temp[i])

            for i in range(len(temp)-1,-1,-1):
                results.append("1" + temp[i])

            return results
        
        combinations = calculate(n)

        results = []
        for comb in combinations:
            results.append(int(comb,2))

        return results

        # codes = [0]
        # offset = 1
        # for i in range(n):
        #     for j in range(len(codes)-1,-1,-1):
        #         codes.append(codes[j]+offset)
        #     offset = offset << 1
        # return codes
# @lc code=end

