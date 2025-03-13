class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []

        for num in range(low,high+1):
            s = str(num)
            flag = True
            for i in range(1,len(s)):
                if ord(s[i]) - ord(s[i-1]) != 1:
                    flag = False
                    break
            if flag:
                res.append(num)

        return res
