#
# @lc app=leetcode id=444 lang=python3
#
# [444] Sequence Reconstruction
#

# @lc code=start
import collections
from collections import deque
from collections import defaultdict
class Solution:
    def sequenceReconstruction(self, nums: List[int], seqs: List[List[int]]) -> bool:
        values = {x for seq in seqs for x in seq}
        graphs = {x:[] for x in values}
        indeg = {x:0 for x in values}

        for seq in seqs:
            for i in range(len(seq)-1):
                s, t = seq[i], seq[i+1]
                graphs[s].append(t)
                indeg[t] += 1
        
        stack = []
        results = []
        for node, count in indeg.items():
            if count == 0:
                stack.append(node)
        
        while stack:
            if len(stack) > 1:
                return False
            source = stack.pop()
            results.append(source)
            for t in graphs[source]:
                indeg[t] -= 1
                if indeg[t] == 0:
                    stack.append(t)

        return len(results) == len(values) and results == nums
        

# @lc code=end

