ur#
# @lc app=leetcode id=1021 lang=python3
#
# [1021] Remove Outermost Parentheses
#

# @lc code=start
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count = 0
        results = ''
        subarray = []

        for i in range(len(s)):
            if s[i] == '(':
                count += 1
                subarray.append(s[i])
            if s[i] == ')':
                count -= 1
                subarray.append(s[i])
            if count == 0:
                results += ''.join(subarray[1:-1])
                subarray = []
        return results
# @lc code=end

