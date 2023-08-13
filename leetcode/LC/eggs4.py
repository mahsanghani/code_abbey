class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        dp = [0, 0]
        m = 0
        while dp[-1] < n:
            for i in range(len(dp) - 1, 0, -1):
                dp[i] += dp[i - 1] + 1
            if len(dp) < k + 1:
                dp.append(dp[-1])
            m += 1
        return m
