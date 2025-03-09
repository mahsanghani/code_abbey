class Solution:
    def bestClosingTime(self, customers: str) -> int:
        penalty = float("inf")
        customers = list(customers)
        prefix = [0]*(len(customers)+1)
        suffix = [0]*(len(customers)+1)

        for i in range(1,len(prefix)):
            prefix[i] = prefix[i-1] + (1 if customers[i-1]=="N" else 0)

        for j in range(len(customers)-1,-1,-1):
            suffix[j] = suffix[j+1] + (1 if customers[j]=="Y" else 0)
            
        for k in range(len(prefix)):
            if prefix[k] + suffix[k] < penalty:
                min_hour = k
                penalty = prefix[k] + suffix[k]

        return min_hour
