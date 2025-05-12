class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        base_satisfied = sum(customers[i] for i in range(len(customers)) if grumpy[i]==0)
        current_extra = sum(customers[i] for i in range(minutes) if grumpy[i]==1)
        max_extra = current_extra
        
        for i in range(minutes,len(customers)):
            if grumpy[i-minutes]==1:
                current_extra -= customers[i-minutes]

            if grumpy[i]==1:
                current_extra += customers[i]

            max_extra = max(max_extra, current_extra)

        return base_satisfied + max_extra
