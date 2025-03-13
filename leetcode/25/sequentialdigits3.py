class Seqs:
    def __init__(self):
        sample = '123456789'
        n = 10
        self.nums = nums = []

        for i in range(2,n):
            for j in range(n-i):
                nums.append(int(sample[j:i+j]))

class Solution:
    s = Seqs()
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        return [x for x in self.s.nums if x>=low and x<=high]
