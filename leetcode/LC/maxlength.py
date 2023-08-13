class Solution:
    def maxLength(self, arr: List[str]) -> int:
        charset = set()
        
        def lap(charset,s):
            prev = set()
            for c in s:
                if c in charset or c in prev:
                    return True
                prev.add(c)
            return False
        
        def dfs(i):
            if i==len(arr):
                return len(charset)
            
            results = 0
            
            if not lap(charset,arr[i]):
                for c in arr[i]:
                    charset.add(c)
                results = dfs(i+1)
                for c in arr[i]:
                    charset.remove(c)
            return max(results,dfs(i+1))
        
        return dfs(0)
