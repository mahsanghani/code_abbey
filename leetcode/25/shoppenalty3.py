class Solution:
    def bestClosingTime(self, customers: str) -> int:
        # hour = 0
        # minP = n
        count = 0
        n = len(customers)
        minP = n
        hour = n
        prefix = []
        suffix = [0]*(n+1)
        
        for cust in customers:
            prefix.append(count)
            if cust == "N":
                count += 1
        prefix.append(count)
        
        for i in range(n-1,-1,-1):
            suffix[i] = suffix[i+1]
            if customers[i] == "Y":
                suffix[i] += 1

        for j in range(n+1):
            penalty = prefix[j] + suffix[j]
            if penalty < minP:
                minP = penalty
                hour = j

        return hour
    