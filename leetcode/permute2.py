class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        results = []
        permutation = []
        count = {n: 0 for n in nums}

        for n in nums:
            count[n] += 1

        def dfs():
            if len(permutation) == len(nums):
                results.append(permutation.copy())
                return

            for n in count:
                if count[n] > 0:
                    permutation.append(n)
                    count[n] -= 1

                    dfs()

                    count[n] += 1
                    permutation.pop()

        dfs()
        return results
