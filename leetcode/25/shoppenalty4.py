class Solution:
    def bestClosingTime(self, customers: str) -> int:
        yes = sum(cust=="Y" for cust in customers)
        minP = yes
        hour = nope = 0

        for i,j in enumerate(customers):
            if j=="Y":
                yes -= 1
            else:
                nope += 1

            penalty = nope + yes

            if penalty < minP:
                hour = i+1
                minP = penalty

        return hour
