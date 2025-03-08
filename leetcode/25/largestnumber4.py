class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        self._quick_sort(nums, 0, len(nums)-1)
        largest_num = ''.join(map(str,nums))
        return '0' if largest_num[0]=='0' else largest_num

    def _quick_sort(self, nums: List[int], left: int, right: int) -> None:
        if left >= right:
            return

        pivot_index = self._partition(nums, left, right)
        self._quick_sort(nums, left, pivot_index-1)
        self._quick_sort(nums, pivot_index+1, right)

    def _partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        low_index = left

        for i in range(left,right):
            if self._compare(nums[i],pivot):
                nums[i],nums[low_index] = nums[low_index],nums[i]
                low_index+=1

        nums[low_index], nums[right] = nums[right], nums[low_index]
        return low_index

    def _compare(self, n1: int, n2: int) -> bool:
        return str(n1)+str(n2) > str(n2)+str(n1)
