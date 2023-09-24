#
# @lc app=leetcode id=71 lang=python3
#
# [71] Simplify Path
#

# @lc code=start
class Solution:
    def simplifyPath(self, s: str) -> str:
        i=0
        stack=[]

        while i<len(s):
            if s[i]=='/':
                i+=1
                continue

            dir=''
            while (i<len(s) and s[i]!='/'):
                dir+=s[i]
                i+=1

            if dir=='.':
                continue

            if dir=='..':
                if stack:
                    stack.pop()
            else:
                stack.append(dir)

        return '/'+'/'.join(stack)
# @lc code=end

