#
# @lc app=leetcode id=752 lang=python3
#
# [752] Open the Lock
#

# @lc code=start
import collections
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        visit = set(deadends)
        queue = collections.deque([("0000", 0)])
        if "0000" in visit:
            return -1
        
        def combinations(password):
            results = []
            for i in range(4):
                num = int(password[i])
                for j in [-1,1]:
                    next_val = (num+j)%10
                    next_pass = password[0:i] + str(next_val) + password[i+1:]
                    results.append(next_pass)
            return results
        
        while queue:
            password, steps = queue.popleft()

            if password == target:
                return steps
            
            for next_level in combinations(password):
                if next_level not in visit:
                    visit.add(next_level)
                    queue.append([next_level, steps+1])

        return -1

# @lc code=end

