class Solution:
    def partitionString(self, s: str) -> int:
        results = []
        unique = set()
        for c in s:
            if c in unique:
                results.append(unique)
                unique = set()
            unique.add(c)
        results.append(unique)
        return len(results)
