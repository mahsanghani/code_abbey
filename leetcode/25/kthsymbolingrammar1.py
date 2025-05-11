class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        prev = ['0']

        for i in range(2,n+1):
            curr = []
            for c in prev:
                if c == '0':
                    curr.append('0')
                    curr.append('1')
                else:
                    curr.append('1')
                    curr.append('0')
            prev = curr

        return int(prev[k-1])
    