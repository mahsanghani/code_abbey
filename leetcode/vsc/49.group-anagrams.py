#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res=[]
        # strs=sorted(strs)
        d=defaultdict(list)
        
        for s in strs:
            d["".join(sorted(s))].append(s)
        
        for k,v in d.items():
            res.append(v)
        
        return sorted(d.values())
# @lc code=end

