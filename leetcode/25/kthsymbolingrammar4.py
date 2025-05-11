class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n==1:
            return 0
        if k&1:
            return self.kthGrammar(n-1,(k+1)//2)
        return self.kthGrammar(n-1,k//2)^1
    