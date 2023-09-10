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
        s = set([i for seq in seqs for i in seq])
        graph = defaultdict(list)
        indeg = defaultdict(int)

        for seq in seqs:
            for i,j in zip(seq[:-1],seq[1:]):
                graph[i].append(j)
                indeg[j] += 1
        
        results = []
        q = [i for i in s if indeg[i]==0]

        while q:
            if len(q)!=1:
                return False
            i = q.pop()
            results.append(i)
            for j in graph[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)

        return results == nums

# @lc code=end

