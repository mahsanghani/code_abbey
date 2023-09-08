#
# @lc app=leetcode id=2408 lang=python3
#
# [2408] Design SQL
#

# @lc code=start
class SQL:

    def __init__(self, names: List[str], columns: List[int]):
        self.tables = [[]]
        for name,cols in zip(names, columns):
            self.tables.append(name[0][cols])


    def insertRow(self, name: str, row: List[str]) -> None:
        self.tables[name].append(row)

    def deleteRow(self, name: str, rowId: int) -> None:
        self.tables[name].pop(rowId-1)

    def selectCell(self, name: str, rowId: int, columnId: int) -> str:
        return self.tables[name][rowId][columnId]


# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# obj.insertRow(name,row)
# obj.deleteRow(name,rowId)
# param_3 = obj.selectCell(name,rowId,columnId)
# @lc code=end

