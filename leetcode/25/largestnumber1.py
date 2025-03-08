class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        res = []
        arr = [str(num) for num in nums]

        while arr:
            maxi = 0
            for i in range(1,len(arr)):
                if arr[i] + arr[maxi] > arr[maxi] + arr[i]:
                    maxi = i
            res.append(arr[maxi])
            arr.pop(maxi)

        result = ''.join(res)
        return result if result[0] != '0' else '0'
    