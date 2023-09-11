#
# @lc app=leetcode id=412 lang=python3
#
# [412] Fizz Buzz
#

# @lc code=start
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        results = []
        for i in range(1,n+1):
            if i%15==0:
                results.append("FizzBuzz")
            elif i%5==0:
                results.append("Buzz")
            elif i%3==0:
                results.append("Fizz")
            else:
                results.append(str(i))

        return results
# @lc code=end

