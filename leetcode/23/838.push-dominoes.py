#
# @lc app=leetcode id=838 lang=python3
#
# [838] Push Dominoes
#

# @lc code=start
from collections import deque
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        d = list(dominoes)
        q = deque()

        for i,j in enumerate(d):
            if j!=".":
                q.append((i,j))

        while q:
            i,j = q.popleft()

            if j=="L" and i>0 and d[i-1]==".":
                q.append((i-1,"L"))
                d[i-1] = "L"
            elif j=="R":
                if i+1<len(d) and d[i+1]==".":
                    if i+2<len(d) and d[i+2]=="L":
                        q.popleft()
                    else:
                        q.append((i+1,"R"))
                        d[i+1] = "R"

        return "".join(d)
# @lc code=end

