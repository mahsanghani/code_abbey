class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.restaurant = defaultdict(lambda: defaultdict(int))

        for i in range(len(foods)):
            if foods[i] in self.restaurant[cuisines[i]]:
                self.restaurant[cuisines[i]][foods[i]] = ratings[i]
            else:
                self.restaurant[cuisines[i]] = {foods[i]: ratings[i]}

        print(self.restaurant)
        return

    def changeRating(self, food: str, newRating: int) -> None:
        for cuisine, menu in self.restaurant.items():
            if food in menu:
                self.restaurant[cuisine][food] = newRating
        return

    def highestRated(self, cuisine: str) -> str:
        print(cuisine)
        print(self.restaurant[cuisine])
        return max(self.restaurant[cuisine], key=self.restaurant[cuisine].get)


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
