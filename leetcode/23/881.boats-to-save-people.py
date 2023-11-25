#
# @lc app=leetcode id=881 lang=python3
#
# [881] Boats to Save People
#

# @lc code=start
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        results = 0
        l,r = 0,len(people)-1

        while l<=r:
            if people[l]+people[r]<=limit:
                results+=1
                l+=1
                r-=1
            elif people[r]<=limit:
                results+=1
                r-=1
        
        return results

# @lc code=end

