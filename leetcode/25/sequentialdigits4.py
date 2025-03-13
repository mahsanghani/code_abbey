class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        n=10
        res=[]
        sample='123456789'

        for i in range(len(str(low)),len(str(high))+1):
            for j in range(n-i):
                num = int(sample[j:j+i])
                if num>=low and num<=high:
                    res.append(num)

        return res
    