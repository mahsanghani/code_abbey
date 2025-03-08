class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        num_strings = [str(num) for num in nums]
        num_strings.sort(key=lambda x: x*10, reverse=True)
        if num_strings[0]=='0':
            return '0'
        return ''.join(num_strings)
