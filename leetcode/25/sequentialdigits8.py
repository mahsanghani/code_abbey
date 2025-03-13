class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []

        def dfs(num):
            if num > high:
                return
            if low <= num <= high:
                res.append(num)
            ones = num%10
            if ones < 9:
                dfs(num*10 + (ones+1))

        for i in range(1,10):
            dfs(i)

        return sorted(res)
