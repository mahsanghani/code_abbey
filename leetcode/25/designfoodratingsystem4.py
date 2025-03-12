from typing import List
from collections import defaultdict
from heapq import heappop, heappush
from sortedcontainers import SortedList

class Food:
    def __init__(self, rating, name):
        self.rating = rating
        self.name = name

    def __lt__(self, other):
        if self.rating == other.rating:
            return self.name < other.name
        return self.rating > other.rating

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.rating_map = {}
        self.cuisine_map = {}
        self.cuisine_food_map = defaultdict(list)

        for i in range(len(foods)):
            self.rating_map[foods[i]] = ratings[i]
            self.cuisine_map[foods[i]] = cuisines[i]

            heapq.heappush(self.cuisine_food_map[cuisines[i]], Food(ratings[i], foods[i]))


    def changeRating(self, food: str, newRating: int) -> None:
        self.rating_map[food] = newRating
        cuisineName = self.cuisine_map[food]
        heapq.heappush(self.cuisine_food_map[cuisineName], Food(newRating, food))


    def highestRated(self, cuisine: str) -> str:
        highest_rated = self.cuisine_food_map[cuisine][0]

        while self.rating_map[highest_rated.name] != highest_rated.rating:
            heapq.heappop(self.cuisine_food_map[cuisine])
            highest_rated = self.cuisine_food_map[cuisine][0]

        return highest_rated.name


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
