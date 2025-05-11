class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        def dfs(n,k,root):
            if n==1:
                return root

            total = 1<<(n-1)
            if k>(total//2):
                return dfs(n-1,k-(total//2),root^1)
            else:
                return dfs(n-1,k,root)

        return dfs(n,k,0)
    