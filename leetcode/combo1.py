class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []

        def dfs(index, current, total):
            if total == target:
                results.append(current.copy())
                return
            if index >= len(candidates) or total > target:
                return

            current.append(candidates[index])
            dfs(index, current, total + candidates[index])
            current.pop()
            dfs(index + 1, current, total)

        dfs(0, [], 0)
        return results
