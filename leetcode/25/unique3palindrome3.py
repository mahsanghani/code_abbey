class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res=0

        for ends in range(ord('a'),ord('z')+1):
            for mid in range(ord('a'),ord('z')+1):
                seq = chr(ends) + chr(mid) + chr(ends)
                idx, found = 0, 0
                
                for c in s:
                    if seq[idx]==c:
                        idx+=1
                        if idx==3:
                            found=1
                            break
                    
                res+=found

        return res