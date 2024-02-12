#
# @lc app=leetcode id=728 lang=python3
#
# [728] Self Dividing Numbers
#

# @lc code=start
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        results = []
        flag = True
        for i in range(left, right+1):
            for c in str(i):
                if int(c)==0 or i%int(c)!=0:
                    flag = False
                    break
            if flag:
                results.append(i)
            flag = True
            i+=1
        return results
                
# @lc code=end

