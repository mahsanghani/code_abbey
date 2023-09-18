#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        results = []

        def dfs(br: str, left: int, right: int):
            if len(br) == 2*n:
                results.append(br)

            if left > 0:
                dfs(br + '(', left-1, right)
            
            if right > 0 and right > left:
                dfs(br + ')', left, right-1)

        dfs('',n,n)

        return results
# @lc code=end

