#
# @lc app=leetcode id=71 lang=python3
#
# [71] Simplify Path
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        i, stack = 0, []

        while i<len(path):
            if path[i]=="/":
                i+=1
                continue

            dir = ""

            while (i<len(path) and path[i]!="/"):
                dir+=path[i]
                i+=1

            if dir==".":
                continue

            if dir=="..":
                if stack:
                    stack.pop()
            else:
                stack.append(dir)
            
        return "/"+"/".join(stack)
# @lc code=end

