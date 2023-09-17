#
# @lc app=leetcode id=394 lang=python3
#
# [394] Decode String
#

# @lc code=start
class Solution:
    def decodeString(self, s: str) -> str:
        it = 0
        num = 0
        stack = ['']

        while (it<len(s)):
            if (s[it].isdigit()):
                num = num*10 + int(s[it])
            elif (s[it] == '['):
                stack.append(num)
                num = 0
                stack.append('')
            elif (s[it] == ']'):
                str1 = stack.pop()
                rep = stack.pop()
                str2 = stack.pop()
                stack.append(str2 + str1 * rep)
            else:
                stack[-1] += s[it]
            it += 1

        return ''.join(stack)
# @lc code=end

