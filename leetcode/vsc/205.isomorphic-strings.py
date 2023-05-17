#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ds=Counter(s)
        dt=Counter(t)

        if ds==dt:
            return True

        ds2=defaultdict(list)
        dt2=defaultdict(list)

        for k,v in ds.items():
            if v>0:
                ds2[v].append(k)

        for k,v in dt.items():
            if v>0:
                dt2[v].append(k)
        
        for k,v in dt2.items():
            if len(v)!=len(ds2[k]):
                return False
        
        return True

# @lc code=end

