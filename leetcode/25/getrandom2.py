import random

class RandomizedSet:

    def __init__(self):
        self.dict = {}
        self.size = 0
        
    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False
        self.dict[val] = 1
        self.size += 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.dict:
            return False
        del self.dict[val]
        self.size -= 1
        return True

    def getRandom(self) -> int:
        idx = random.randint(0, self.size-1)
        return list(self.dict.keys())[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()