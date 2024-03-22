#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#
# @lc code=start
from collections import deque, defaultdict
class Solution:
    def ladderLength(self, start: str, finish: str, words: List[str]) -> int:
        adj = defaultdict(list)
        words.append(start)
        visit = set([start])
        q = deque([start])
        results = 1

        if finish not in words:
            return 0

        for word in words:
            for j in range(len(word)):
                pattern = word[:j] + "*" + word[j+1:]
                adj[pattern].append(word)

        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word==finish:
                    return results

                for j in range(len(word)):
                    pattern = word[:j] + "*" + word[j+1:]
                    for n in adj[pattern]:
                        if n not in visit:
                            visit.add(n)
                            q.append(n)

            results+=1
        return 0

# @lc code=end

