class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        base = sum(customers[i] for i in range(len(customers)) if grumpy[i]==0)
        curr = sum(customers[i] for i in range(minutes) if grumpy[i]==1)
        extra = curr
        
        for i in range(minutes, len(customers)):
            if grumpy[i-minutes]==1:
                curr -= customers[i-minutes]

            if grumpy[i]==1:
                curr += customers[i]

            extra = max(curr, extra)

        return base + extra
