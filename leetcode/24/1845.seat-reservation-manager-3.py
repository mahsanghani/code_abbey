#
# @lc app=leetcode id=1845 lang=python3
#
# [1845] Seat Reservation Manager
#
# @lc code=start
from heapq import heappush, heappop
class SeatManager:
    def __init__(self, n: int):
        self.mark = 1
        self.seats = []

    def reserve(self) -> int:
        if self.seats:
            return heappop(self.seats)
        self.seat = self.mark
        self.mark += 1
        return self.seat

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.seats, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
# @lc code=end

