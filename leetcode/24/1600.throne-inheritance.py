#
# @lc app=leetcode id=1600 lang=python3
#
# [1600] Throne Inheritance
#
# @lc code=start
from collections import defaultdict
class ThroneInheritance:
    def __init__(self, kingName: str):
        self.nation = defaultdict(list)
        self.king = kingName
        self.dead = set()

    def birth(self, parentName: str, childName: str) -> None:
        self.nation[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        self.res = []
        self.dfs(self.king)
        return self.res

    def dfs(self, curr) -> None:
        if curr not in self.dead:
            self.res.append(curr)
        for child in self.nation[curr]:
            self.dfs(child)

# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
# @lc code=end

