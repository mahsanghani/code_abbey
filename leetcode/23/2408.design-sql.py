#
# @lc app=leetcode id=2408 lang=python3
#
# [2408] Design SQL
#

# @lc code=start
import collections
from collections import defaultdict
class SQL:

    def __init__(self, names: List[str], columns: List[int]):
        self.tables = {name:[] for name in names}

    def insertRow(self, name: str, row: List[str]) -> None:
        self.tables[name].append(row)

    def deleteRow(self, name: str, rowId: int) -> None:
        self.tables[name][rowId-1] = None

    def selectCell(self, name: str, rowId: int, columnId: int) -> str:
        return self.tables[name][rowId-1][columnId-1]


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# obj.insertRow(name,row)
# obj.deleteRow(name,rowId)
# param_3 = obj.selectCell(name,rowId,columnId)
# @lc code=end

