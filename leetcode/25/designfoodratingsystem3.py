from typing import List
from collections import defaultdict
from heapq import heappop, heappush
from sortedcontainers import SortedList


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food = {}
        self.cuis = defaultdict(SortedList)

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food[food] = (cuisine, rating)
            self.cuis[cuisine].add((-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.food[food]
        self.food[food] = cuisine, newRating
        self.cuis[cuisine].remove((-rating, food))
        self.cuis[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.cuis[cuisine][0][1]
        

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
