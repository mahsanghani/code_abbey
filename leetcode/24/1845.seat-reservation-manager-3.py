#
# @lc app=leetcode id=1845 lang=python3
#
# [1845] Seat Reservation Manager
#
# @lc code=start
class SeatManager:
    def __init__(self, n: int):
        self.size = n
        self.seats = [None]*self.size

    def reserve(self) -> int:
        for i in range(self.size):
            if self.seats[i]==None:
                self.seats[i] = i+1
                return i+1

    def unreserve(self, seatNumber: int) -> None:
        if seatNumber in self.seats:
            self.seats[seatNumber-1] = None


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
# @lc code=end

