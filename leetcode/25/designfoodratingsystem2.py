from collections import defaultdict
from heapq import heappop, heappush
``
class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuis = cuisines
        self.rate = ratings
        self.heap = defaultdict(list)
        self.idxs = {f:i for i,f in enumerate(foods)}

        for i, (f,c,r) in enumerate(zip(foods, cuisines, ratings)):
            heappush(self.heap[c], (-r,f,i))

    def changeRating(self, food: str, newRating: int) -> None:
        idx = self.idxs[food]
        self.rate[idx] = newRating
        cuisine = self.cuis[idx]
        heappush(self.heap[cuisine], (-newRating, food, idx))

    def highestRated(self, cuisine: str) -> str:
        neg, food, idx = self.heap[cuisine][0]
        
        while -neg != self.rate[idx]:
            heappop(self.heap[cuisine])
            neg, food, idx = self.heap[cuisine][0]

        return food

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
