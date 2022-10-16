class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        results = []

        if len(s) > 12:
            return results

        def dfs(i, dots, cur):
            if dots == 4 and i == len(s):
                results.append(cur[:-1])
                return
            if dots > 4:
                return

            for j in range(i, min(i + 3, len(s))):
                if int(s[i:j + 1]) < 256 and (i == j or s[i] != "0"):
                    dfs(j + 1, dots + 1, cur + s[i:j + 1] + ".")

        dfs(0, 0, "")
        return results
