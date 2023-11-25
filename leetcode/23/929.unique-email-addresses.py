#
# @lc app=leetcode id=929 lang=python3
#
# [929] Unique Email Addresses
#

# @lc code=start
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        t=0
        d=defaultdict(list)
        
        for e in emails:
            d[e.split('@')[1]].append(e.split('@')[0].split('+')[0].replace('.',''))
        
        for k,v in d.items():
            t+=len(set(v))

        return t
# @lc code=end

