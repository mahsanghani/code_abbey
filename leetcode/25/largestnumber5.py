class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        sorted_nums = self._merge_sort(nums, 0, len(nums)-1)
        largest_num = ''.join(map(str, sorted_nums))
        return '0' if largest_num[0] == '0' else largest_num

    def _merge_sort(self, nums: List[int], left: int, right: int) -> List[int]:
        if left >= right:
            return [nums[left]]
        mid = left + (right - left) // 2
        left_half = self._merge_sort(nums, left, mid)
        right_half = self._merge_sort(nums, mid+1, right)
        return self._merge(left_half, right_half)

    def _merge(self, left_half: List[int], right_half: List[int]) -> List[int]:
        sorted_nums = []
        left_index = 0
        right_index = 0
        
        while left_index < len(left_half) and right_index < len(right_half):
            if self._compare(left_half[left_index], right_half[right_index]):
                sorted_nums.append(left_half[left_index])
                left_index += 1
            else:
                sorted_nums.append(right_half[right_index])
                right_index += 1

        sorted_nums.extend(left_half[left_index:])
        sorted_nums.extend(right_half[right_index:])
        return sorted_nums

    def _compare(self, n1: int, n2: int) -> bool:
        return str(n1)+str(n2) > str(n2)+str(n1)
