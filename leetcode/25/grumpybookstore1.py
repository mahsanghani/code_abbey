class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        left = 0
        window = 0
        max_window = 0
        satisfied = 0

        for right in range(len(customers)):
            if grumpy[right]:
                window += customers[right]
            else:
                satisfied += customers[right]

            if right-left+1>minutes:
                if grumpy[left]:
                    window -= customers[left]
                left += 1

            max_window = max(window, max_window)

        return satisfied + max_window
