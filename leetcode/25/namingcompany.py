from collections import defaultdict

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        results = 0
        d = defaultdict(set)

        for word in ideas:
            d[word[0]].add(word[1:])
            
        for c1 in d:
            for c2 in d:
                if c1==c2:
                    continue

                intersect = sum(1 for word in d[c1] if word in d[c2])
                distinct1 = len(d[c1]) - intersect
                distinct2 = len(d[c2]) - intersect
                results += distinct1 * distinct2

        return results
