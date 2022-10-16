class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []
        candidates.sort()

        def dfs(index, current, total):
            if total == 0:
                results.append(current.copy())

            if total <= 0:
                return

            previous = -1

            for i in range(index, len(candidates)):
                if candidates[i] == previous:
                    continue
                current.append(candidates[i])
                dfs(i + 1, current, total - candidates[i])
                current.pop()
                previous = candidates[i]

        dfs(0, [], target)
        return results
