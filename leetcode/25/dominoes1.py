class Solution:
    def cmp(self, a, b):
        return (a > b) - (a < b) 
    
    def pushDominoes(self, dominoes: str) -> str:
        symbols = [(i,x) for i,x in enumerate(dominoes) if x!='.']
        symbols = [(-1,'L')] + symbols + [(len(dominoes),'R')]

        res = list(dominoes)

        for (i,x), (j,y) in zip(symbols, symbols[1:]):
            if x==y:
                for k in range(i+1,j):
                    res[k] = x
            elif x>y:
                for k in range(i+1,j):
                    res[k] = '.LR'[self.cmp(k-i,j-k)]

        return ''.join(res)