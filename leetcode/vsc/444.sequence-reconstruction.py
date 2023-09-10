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
        graph = defaultdict(list)
        indeg = defaultdict(int)

        for seq in seqs:
            for i in range(1, len(seq)):
                graph[seq[i-1]].append(seq[i])
                indeg[seq[i]] += 1

        i = 1
        stack = [nums[0]]
        if indeg[nums[0]] > 0:
            return False
        
        while stack:
            node = stack.pop()
            for child in graph[node]:
                indeg[child] -= 1
                if not indeg[child]:
                    if stack or child != nums[i]:
                        return False
                    stack.append(child)
                    i += 1

        return i == len(nums)

# @lc code=end

