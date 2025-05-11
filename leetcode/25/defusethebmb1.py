class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        results = [0]*n

        if k == 0:
            return results

        if k > 0:
            for i in range(n):
                for j in range(1,k+1):
                    results[i] += code[(i+j)%n]

        
        if k < 0:
            for i in range(n):
                for j in range(1,abs(k)+1):
                    results[i] += code[(i-j+n)%n]

        return results
