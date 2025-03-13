class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        nums = '123456789'

        for d in range(2,10):
            for i in range(9-d+1):
                num = int(nums[i:i+d])
                if num>high:
                    break
                if low<=num<=high:
                    res.append(num)

        return res
