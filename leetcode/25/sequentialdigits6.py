class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        low_digit = len(str(low))
        high_digit = len(str(high))

        for digits in range(low_digit, high_digit+1):
            for start in range(1,10):
                if start + digits > 10:
                    break
                num = start
                prev = start
                for i in range(digits-1):
                    num = num*10
                    prev += 1
                    num += prev
                if low <= num <= high:
                    res.append(num)

        return res
