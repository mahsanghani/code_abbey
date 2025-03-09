import random

class RandomizedSet:

    def __init__(self):
        self.dict = {}
        self.list = []

    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False
        else:
            self.dict[val] = len(self.list)
            self.list.append(val)
            return True

    def remove(self, val: int) -> bool:
        if val not in self.dict:
            return False
        idx = self.dict[val]
        last = self.list[-1]
        self.list[idx] = last
        self.dict[last] = idx
        self.list.pop()
        del self.dict[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.list)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()