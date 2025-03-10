class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        hour = n
        minP = n
        
        for i in range(n+1):
            penalty = 0
            for j in range(i):
                if customers[j]=="N":
                    penalty+=1
            for k in range(i,n):
                if customers[k]=="Y":
                    penalty+=1

            if penalty < minP:
                minP = penalty
                hour = i

        return hour
