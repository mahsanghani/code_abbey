#
# @lc app=leetcode id=1845 lang=python3
#
# [1845] Seat Reservation Manager
#
# @lc code=start
from sortedcontainers import SortedSet
class SeatManager:
    def __init__(self, n: int):
        self.mark = 1
        self.seats = SortedSet()

    def reserve(self) -> int:
        if self.seats:
            return self.seats.pop(0)
        self.seat = self.mark
        self.mark += 1
        return self.seat

    def unreserve(self, seatNumber: int) -> None:
        self.seats.add(seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
# @lc code=end

