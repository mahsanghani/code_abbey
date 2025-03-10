class Solution:
    def bestClosingTime(self, customers: str) -> int:
        hour = pen = minP = 0
        
        for i,j in enumerate(customers):
            pen += 1 if j=="Y" else -1

            if pen > minP:
                minP = pen
                hour = i+1

        return hour
    