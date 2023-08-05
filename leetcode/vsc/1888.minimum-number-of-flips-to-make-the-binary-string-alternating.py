#
# @lc app=leetcode id=1888 lang=python3
#
# [1888] Minimum Number of Flips to Make the Binary String Alternating
#

# @lc code=start
class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s = s + s
        results = len(s)
        alt1, alt2 = "", ""
        l, r, diff1, diff2 = 0,0,0,0

        for i in range(len(s)):
            alt1 += "0" if i % 2 else "1"
            alt2 += "1" if i % 2 else "0"

        for r in range(len(s)):
            if s[r]!=alt1[r]:
                diff1+=1
            if s[r]!=alt2[r]:
                diff2+=1
            
            if (r-l+1) > n:
                if s[1]!=alt1[l]:
                    diff1-=1
                if s[l]!=alt2[l]:
                    diff2-=1
                l+=1
            
            if (r-l+1)==n:
                results = min(results,diff1,diff2)

        return results
# @lc code=end

