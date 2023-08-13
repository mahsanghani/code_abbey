class Solution:
    def numTrees(self, n: int) -> int:
        num = [1] * (n + 1)

        for node in range(2, n + 1):
            total = 0
            for root in range(1, node + 1):
                left = root - 1
                right = node - root
                total += num[left] * num[right]
            num[node] = total
        return num[n]
