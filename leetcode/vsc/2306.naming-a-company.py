#
# @lc app=leetcode id=2306 lang=python3
#
# [2306] Naming a Company
#

# @lc code=start
import collections
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        results = 0
        words = collections.defaultdict(set)

        for word in ideas:
            words[word[0]].add(word[1:])
        
        for c1 in words:
            for c2 in words:
                if c1 == c2:
                    continue
                intersect = 0
                for w in words[c1]:
                    if w in words[c2]:
                        intersect += 1
                
                distinct1 = len(words[c1]) - intersect
                distinct2 = len(words[c2]) - intersect
                results += distinct1 * distinct2
        
        return results
# @lc code=end

