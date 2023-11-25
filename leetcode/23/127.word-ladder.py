#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#

# @lc code=start
import collections
from collections import deque
from collections import defaultdict
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        adj = collections.defaultdict(list)
        wordList.append(beginWord)

        results = 1
        visit = set([beginWord])
        q = collections.deque([beginWord])

        if endWord not in wordList:
            return 0
        
        for word in wordList:
            for j in range(len(word)):
                pattern = word[:j] + "*" + word[j+1:]
                adj[pattern].append(word)

        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return results
                for j in range(len(word)):
                    pattern = word[:j] + "*" + word[j+1:]
                    for neighbour in adj[pattern]:
                        if neighbour not in visit:
                            visit.add(neighbour)
                            q.append(neighbour)
            results+=1
        return 0

# @lc code=end

