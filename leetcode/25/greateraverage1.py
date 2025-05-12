class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        win = sum(arr[:k])
        res = 1 if win//k>=threshold else 0

        for i in range(k,len(arr)):
            win = win - arr[i-k] + arr[i]

            if win//k>=threshold:
                res+=1

        return res
