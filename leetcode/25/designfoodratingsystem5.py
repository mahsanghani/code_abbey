from typing import List
from collections import defaultdict
from heapq import heappop, heappush
from sortedcontainers import SortedSet

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.rating_map = {}
        self.cuisine_map = {}
        self.cuisine_food_map = defaultdict(SortedSet)

        for i in range(len(foods)):
            self.rating_map[foods[i]] = ratings[i]
            self.cuisine_map[foods[i]] = cuisines[i]
            self.cuisine_food_map[cuisines[i]].add((-ratings[i], foods[i]))


    def changeRating(self, food: str, newRating: int) -> None:
        name = self.cuisine_map[food]
        old = (-self.rating_map[food], food)
        self.cuisine_food_map[name].remove(old)
        self.rating_map[food] = newRating
        self.cuisine_food_map[name].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        highest_rated = self.cuisine_food_map[cuisine][0]
        return highest_rated[1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
