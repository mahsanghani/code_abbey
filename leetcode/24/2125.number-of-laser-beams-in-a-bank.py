#
# @lc app=leetcode id=2125 lang=python3
#
# [2125] Number of Laser Beams in a Bank
#

# @lc code=start
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        i = 0
        results = 0
        n=len(bank)
        while i<n-1:
            if '1' not in bank[i]:
                bank.pop(i)
                i-=1
                n-=1
            if n>1:
                if i<0:
                    i=0
                results+=bank[i].count('1')*bank[i+1].count('1')
            i+=1
        return results
# @lc code=end

